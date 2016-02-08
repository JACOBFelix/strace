#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "strace.h"

void			my_wait(pid_t pid)
{
  int			status;

  if (wait4(pid, &status, WUNTRACED, NULL) == -1)
    exit(dprintf(2, "Fail Wait4\n"));
  check_status(status, pid);
}

void			check_status(int status, pid_t pid)
{
  siginfo_t			sig;
  int				b;

  if (WIFEXITED(status))
    exit(dprintf(2, ") = ?\n"));
  if ((b = WIFSIGNALED(status)) != 0)
    {
      if (b == 5 || b == 17)
	return ;
      if (ptrace(PTRACE_GETSIGINFO, pid, NULL, &sig) == -1)
	return ;
    }
  if (WIFSTOPPED(status) != 0)
    {
      if (WSTOPSIG(status) != 5 && WSTOPSIG(status) != 17 &&
	  WSTOPSIG(status) != 19)
	exit(dprintf(2, "Child Processes has been kill by the signal number\
 : %d\n",  WSTOPSIG(status)));
    }
}
