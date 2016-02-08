#include <stdio.h>
#include <string.h>
#include "strace.h"
#include "shared.h"

t_ret			g_rettab[] = {{INT8, &printchar},
				      {UINT8, &printuchar},
				      {INT16, &printshort},
				      {UINT16, &printushort},
				      {INT32, &printint},
				      {UINT32, &printuint},
				      {INT64, &printlong},
				      {UINT64, &printulong},
				      {GENERIC_PTR, &printptr},
				      {VOID, &printvoid},
				      {INT8PTR, &printptr},
				      {0, NULL}};

void			print_ret(t_callsys const *const sys UNUSED,
				  unsigned long long int ret UNUSED,
				  pid_t pid)
{
  int			i;

  i = -1;
  while (g_rettab[++i].type != 0 && g_rettab[i].fct != NULL)
    {
      if (strcmp("brk", sys->name) == 0)
	{
	  dprintf(2, ")\t=\t%p\n", (void *)ret);
	  break ;
	}
      else if (sys->ret_type == g_rettab[i].type)
      	{
      	  dprintf(2, ")\t=\t");
      	  g_rettab[i].fct(ret, pid);
      	  break ;
      	}
    }
  dprintf(2, "\n");
}
