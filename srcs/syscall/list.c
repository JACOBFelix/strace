#include <string.h>
#include <stdlib.h>
#include "my_syscall.h"

static int	push_back(t_list **list, t_list *new)
{
  t_list	*tmp;

  if (((tmp = *list)) == NULL)
    {
      *list = new;
      return (SUCCESS);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  return (SUCCESS);
}

int		add_element(t_list **list, void *data)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (my_perror(ERR, MALLOC_ERR));
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return (push_back(list, new));
}

void		free_syscall(t_list *list)
{
  if (list == NULL)
    return ;
  if (list->data != NULL)
    {
      free(((t_syscall *)(list->data))->name);
      free(((t_syscall *)(list->data))->proto);
      free(list->data);
    }
  free_syscall(list->next);
  free(list);
}
