#include <stdio.h>
#include "shared.h"

void		printvararg(unsigned long long int ret UNUSED,
			    pid_t pid UNUSED)
{
  dprintf(2, "...");
}

void		printinttab(unsigned long long int ret UNUSED,
			    pid_t pid UNUSED)
{
  int		a;
  int		b;

  a = 0xffffffff00000000 > 32;
  b = 0x00000000ffffffff;
  dprintf(2, "[%d, %d]", a, b);
}

void		printcapuserdata(unsigned long long int ret UNUSED,
				 pid_t pid UNUSED)
{
  if ((void *)ret == NULL)
    dprintf(2, "NULL");
  else
    dprintf(2, "%p", (void *)ret);
}

void		printtimevaltab(unsigned long long int ret UNUSED,
				pid_t pid UNUSED)
{
  if ((void *)ret == NULL)
    dprintf(2, "NULL");
  else
    dprintf(2, "%p", (void *)ret);
}

void		printtimespectab(unsigned long long int ret UNUSED,
				 pid_t pid UNUSED)
{
  if ((void *)ret == NULL)
    dprintf(2, "NULL");
  else
    dprintf(2, "%p", (void *)ret);
}
