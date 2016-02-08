#include <stdio.h>
#include "strace.h"

void		printint(unsigned long long int ret,
			 pid_t pid UNUSED)
{
  if ((long long int)ret == -2)
    ret = -1;
  dprintf(2, "%lld", ret);
}

void		printuint(unsigned long long int ret,
			  pid_t pid UNUSED)
{
  dprintf(2, "%llu", ret);
}

void		printlong(unsigned long long int ret,
			  pid_t pid UNUSED)
{
  dprintf(2, "%lld", ret);
}

void		printulong(unsigned long long int ret,
			   pid_t pid UNUSED)
{
  dprintf(2, "%llu", ret);
}
void		printptr(unsigned long long int ret,
			 pid_t pid UNUSED)
{
  if (ret == 0)
    dprintf(2, "NULL");
  else
    dprintf(2, "%p", (void *)ret);
}
