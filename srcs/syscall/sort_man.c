#include <string.h>
#include <stdlib.h>
#include "my_syscall.h"

static int	could_be_interessant(t_list *syscall,
				     t_list *man)
{
  while (syscall)
    {
      if (strstr(((char *)(man->data)),
		 ((char *)(((t_syscall *)(syscall->data))->name))) != NULL)
	((t_syscall *)(syscall->data))->man_linker += 1;
      syscall = syscall->next;
    }
  return (SUCCESS);
}

static void	delete_man(t_list *list)
{
  t_list	*prev;
  t_list	*next;

  free(list->data);
  prev = list->prev;
  next = list->next;
  if (next != NULL)
    next->prev = prev;
  if (prev != NULL)
    prev->next = next;
  free(list);
}

void		sort_man(t_list *syscall UNUSED,
			 t_list **man UNUSED)
{
  t_list	*tmp;
  t_list	*buf;

  tmp = (*man)->next;
  while (tmp)
    {
      if (could_be_interessant(syscall, tmp) == FAILURE)
	{
	  buf = tmp;
	  tmp = tmp->next;
	  delete_man(buf);
	}
      else
	tmp = tmp->next;
    }
}
