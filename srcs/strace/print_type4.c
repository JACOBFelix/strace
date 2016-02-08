#include <sys/ptrace.h>
#include <stdio.h>
#include "strace.h"

void		printvoid(unsigned long long int ret UNUSED,
			  pid_t pid UNUSED)
{
}

void		printcapuserdatat(unsigned long long int ret UNUSED,
				  pid_t pid)
{
  int		a;
  int		b;
  int		c;
  long		r;

  if ((void *)ret == NULL)
    {
      dprintf(2, "NULL");
      return ;
    }
  if ((r = ptrace(PTRACE_PEEKTEXT, pid, (void *)ret, NULL)) == -1)
    {
      dprintf(2, "NULL");
      return ;
    }
  a = 0xffffffff00000000 >> 32;
  b = 0x00000000ffffffff;
  if ((r = ptrace(PTRACE_PEEKTEXT, pid, ((void *)(ret + 8)), NULL)) == -1)
    {
      dprintf(2, "NULL");
      return ;
    }
  c = 0xffffffff00000000 >> 32;
  dprintf(2, "[%d, %d, %d]", a, b, c);
}
