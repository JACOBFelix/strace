#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include "strace.h"
#include "list_syscall.h"

pid_t				pid_trace;

void				signal_trace(int a UNUSED)
{
  printf("Pid = %u\n", pid_trace);
  if (wait4(pid_trace, NULL, WUNTRACED, NULL) == -1)
    dprintf(2, "Wait failed\n");
  if (ptrace(PTRACE_INTERRUPT, pid_trace, NULL, NULL) == -1)
    dprintf(2, "Interrupt failed\n");
  if (ptrace(PTRACE_DETACH, pid_trace, NULL, NULL) == -1)
    dprintf(2, "Detach failed\n");
  exit(0);
}

static void			follow_trace_pid(struct user_regs_struct reg,
						 int was_sys UNUSED,
						 int sys UNUSED,
						 long ret UNUSED)
{
  while (ptrace(PTRACE_SINGLESTEP, pid_trace, NULL, NULL) != -1)
    {
      my_wait(pid_trace);
      if (ptrace(PTRACE_GETREGS, pid_trace, NULL, ((void *)(&reg))) != -1)
	{
	  if ((ret = ptrace(PTRACE_PEEKTEXT, pid_trace, ((void *)(reg.rip)),
			    NULL)) == -1)
	    exit(dprintf(2, "ptrace(PREACE_PEEKTEXT Failed\n"));
	  else
	    {
	      if (was_sys == 1 && ((--was_sys) == 0))
		print_ret(&g_arg[sys], reg.rax, pid_trace);
	      else
		{
		  ret &= 0x000000000000ffff;
		  if (was_sys == 0 && (ret == 0x050FU || ret == 0x80CDU ||
				       ret == 0x340FU) && ((++was_sys) == 1))
		    moulitrixdecon(&sys, reg, pid_trace);
		}
	    }
	}
    }
}

ALWAYS_INLINE int		trace_pid(char const *const str UNUSED)
{
  struct user_regs_struct	reg;

  if (str == NULL)
    return (dprintf(2, "%s\n", UNDEF_PID) - sizeof(UNDEF_PID) - 1 + FAILURE);
  pid_trace = atoi(str);
  signal(SIGINT, &signal_trace);
  if (ptrace(PTRACE_ATTACH, pid_trace, NULL, NULL) == -1)
    return (dprintf(2, "Error can't attach the process\n"));
  my_wait(pid_trace);
  follow_trace_pid(reg, 0, 0, 0);
  exit(0);
  return (SUCCESS);
}
