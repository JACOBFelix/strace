#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include "strace.h"
#include "list_syscall.h"

int				num_syscall(unsigned long long int rax,
					    pid_t pid)
{
  int				i;

  i = -1;
  while (g_arg[++i].name != NULL && g_arg[i].opcode != (int)rax)
    ;
  if (g_arg[i].name == NULL)
    {
      if (ptrace(PTRACE_KILL, pid, NULL, NULL) == -1)
	dprintf(2, "Can't kill the process attached : %u\n", pid);
      exit(dprintf(2, "Invalid syscall : %llu\n", rax));
    }
  return (i);
}
