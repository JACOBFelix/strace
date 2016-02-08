#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_syscall.h"

ALWAYS_INLINE static int	proto_in_two_line(t_list *list,
						  char *buffer,
						  FILE *fd)
{
  char		*tmp;
  size_t	s;

  tmp = NULL;
  s = 0;
  if (getline(&tmp, &s, fd) == -1)
    return (my_perror(ERR, PROTO_ERR));
  if (asprintf(&((t_syscall *)(list->data))->proto, "%s%s", buffer, tmp)
      == -1)
    {
      free(tmp);
      return (my_perror(ERR, MALLOC_ERR));
    }
  free(tmp);
  return (SUCCESS);
}

ALWAYS_INLINE static int	recup_full_proto(t_list *list,
						 char *buffer)
{
  if (asprintf(&((t_syscall *)(list->data))->proto, "%s", buffer) == -1)
    return (my_perror(ERR, MALLOC_ERR));
  return (SUCCESS);
}

static int	parseman(t_list *list,
			 char *needed,
			 FILE *fd)
{
  char		*buffer;
  char		*ret;
  size_t	s;
  int		a;

  buffer = NULL;
  s = 0;
  a = SUCCESS;
  while (getline(&buffer, &s, fd) != -1)
    {
      if ((ret = strstr(buffer, needed)) != NULL)
	{
	  if (strstr(ret, ";") == NULL)
	    a = proto_in_two_line(list, buffer, fd);
	  else
	    a = recup_full_proto(list, buffer);
	  free(buffer);
	  return (a);
	}
      free(buffer);
      buffer = NULL;
      s = 0;
    }
  free(buffer);
  return (a);
}

int		syscall_getproto(t_list *list,
				 char *needed)
{
  FILE		*fd;
  int		a;

  if ((fd = fopen("file", "r")) == NULL)
    return (my_perror(ERR, ERR_OPEN_FILE));
  a = parseman(list, needed, fd);
  fclose(fd);
  if (((t_syscall *)(list->data))->proto == NULL)
    return (a);
  return (parse_prototype(list));
  return (a);
}
