#include <sys/ptrace.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strace.h"
#include "list_syscall.h"

pid_t				g_pid;

static void			exec_son(char const *exec,
					 char const *const tab[],
					 char const *const envp[])
{
  if (ptrace(PTRACE_TRACEME, 0) == -1)
    {
      dprintf(2, "Error can't trace child\n");
      exit(0);
    }
  execve((char *)exec, (char *const *)tab, (char *const *)envp);
  dprintf(2, "execve_failed\n");
  exit(0);
}

void				moulitrixdecon(int *sys,
					       struct user_regs_struct reg,
					       pid_t pid)
{
  *sys = num_syscall(reg.rax, pid);
  dprintf(2, "%s", g_arg[reg.rax].name);
  print_arg(&g_arg[*sys], reg, pid);
}

static void			exec_strace(pid_t pid,
					    int sys,
					    int was_sys,
					    long ret)
{
  struct user_regs_struct	reg;

  while (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) != -1)
    {
      my_wait(pid);
      if (ptrace(PTRACE_GETREGS, pid, NULL, ((void *)(&reg))) != -1)
	{
	  if ((ret = ptrace(PTRACE_PEEKTEXT, pid, ((void *)(reg.rip)), NULL))
	      == -1)
	    exit(dprintf(2, "ptrace(PREACE_PEEKTEXT Failed\n"));
	  else
	    {
	      if (was_sys == 1 && ((was_sys -= 1) == 0))
		print_ret(&g_arg[sys], reg.rax, pid);
	      else
		{
		  ret &= 0x000000000000ffff;
		  if ((ret == 0x050FU || ret == 0x80CDU || ret == 0x340FU)
		      && ((++was_sys) == 1))
		    moulitrixdecon(&sys, reg, pid);
		}
	    }
	}
    }
}

void				handle_sig_fork(int a UNUSED)
{
  dprintf(2, "Bye\n");
  if (kill(g_pid, SIGINT) == -1)
    dprintf(2, "Can't kill the son\n");
  exit(0);
}

ALWAYS_INLINE int		exec(char const *exec UNUSED,
				     char const *const tab[] UNUSED,
				     char const *const envp[] UNUSED)
{
  if ((g_pid = fork()) == 0)
    exec_son(exec, tab, envp);
  else if (g_pid == -1)
    exit(dprintf(2, "Fork failed\n"));
  else
    {
      signal(SIGINT, &handle_sig_fork);
      my_wait(g_pid);
      exec_strace(g_pid, 0, 0, 0);
    }
  exit(0);
  return (SUCCESS);
}
