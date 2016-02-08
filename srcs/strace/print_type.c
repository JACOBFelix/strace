#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include "strace.h"

void		printchar(unsigned long long int ret,
			  pid_t pid UNUSED)
{
  dprintf(2, "%c", (char)ret);
}

void		printuchar(unsigned long long int ret,
			   pid_t pid UNUSED)
{
  dprintf(2, "%llu", ret);
}

void		printshort(unsigned long long int ret,
			   pid_t pid UNUSED)
{
  ret &= 0x000000000000ffff;
  dprintf(2, "%lld", ret);
}

void		printushort(unsigned long long int ret,
			    pid_t pid UNUSED)
{
  ret &= 0x000000000000ffff;
  dprintf(2, "%llu", ret);
}

void		printcharptr(unsigned long long int ret,
			     pid_t pid)
{
  char		tab[9];
  long		t;
  int		i;

  if ((void *)ret == NULL)
    {
      dprintf(2, "NULL");
      return ;
    }
  memset(tab, 0, 9);
  if ((t = ptrace(PTRACE_PEEKTEXT, pid, (void *)ret, NULL)) == -1)
    return ;
  memcpy(tab, &t, sizeof(long));
  dprintf(2, "%s", tab);
  i = -1;
  while (tab[++i] != 0)
    ;
  if (i == 8)
    printcharptr(ret + 8, pid);
}
