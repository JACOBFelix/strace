#include <stdio.h>
#include "my_syscall.h"

void		print(t_list *list UNUSED,
		      int const output)
{
  t_syscall	*sys;
  int		i;

  i = 0;
  dprintf(output, "%s", HEAD1);
  while (list)
    {
      if (i != 0)
	dprintf(output, "		                   ");
      ++i;
      sys = ((t_syscall *)(list->data));
      dprintf(output, "{\"%s\", %d, %d, %d, %d, %d,\n\
		                    %d, %d, %d},\n", sys->name,
	      sys->opcode, sys->ret_type, sys->type_first_arg,
	      sys->type_sec_arg, sys->type_third_arg, sys->type_fourth_arg,
	      sys->type_fifth_arg, sys->type_sixth_arg);
      list = list->next;
    }
  dprintf(output, "		                   ");
  dprintf(output, "{NULL, 4242, 0, 0, 0, 0, 0, 0, 0}};\n\n%s\n", ENDIF);
}
