#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_syscall.h"

ALWAYS_INLINE static int	parse_ret_unsigned(char *ret UNUSED,
						   char *proto_dup UNUSED,
						   t_list *list UNUSED)
{
  char				*next;
  char				*buffer;
  int				a;

  if ((next = strtok(NULL, " \t\n,()")) == NULL)
    return (SUCCESS);
  if (asprintf(&buffer, "%s %s", ret, next) == -1)
    return (SUCCESS);
  a = parse_ret_normal(buffer, proto_dup, list);
  free(buffer);
  return (a);
}

ALWAYS_INLINE static int	parse_ret(t_list *list UNUSED,
					  char *proto_dup UNUSED)
{
  char				*ret;

  if ((ret = strtok(proto_dup, " \t\n,()")) == NULL)
    return (SUCCESS);
  if (strcmp(ret, "unsigned") == 0)
    {
      if (parse_ret_unsigned(ret, proto_dup, list) == FAILURE)
	return (FAILURE);
      return (SUCCESS);
    }
  else
    return (parse_ret_normal(ret, proto_dup, list));
}

int	parse_prototype(t_list *list UNUSED)
{
  char	*proto_dup;

  if ((proto_dup = strdup(((t_syscall *)(list->data))->proto)) == NULL)
    return (my_perror(ERR, MALLOC_ERR));
  if (parse_ret(list, proto_dup) == FAILURE)
    {
      free(proto_dup);
      return (FAILURE);
    }
  free(proto_dup);
  return (SUCCESS);
}
