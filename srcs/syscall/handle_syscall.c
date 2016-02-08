#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_syscall.h"

ALWAYS_INLINE static int trix(char *tmp, char *str)
{
  free(tmp);
  free(str);
  return (my_perror(ERR, MALLOC_ERR));
}

int	handle_syscall(t_list *list)
{
  char	*str;
  char	*tmp;
  char	*buf;
  char	*buffer;

  while (list)
    {
      if ((tmp = particular_case(list, 0)) == NULL)
	return (my_perror(ERR, MALLOC_ERR));
      buf = tmp;
      if (buf[0] == '2' || buf[0] == '1' || buf[0] == '3')
	buf += 2;
      if (asprintf(&str, "man %s > file", tmp) == -1)
	return (trix(tmp, NULL));
      if (asprintf(&buffer, "%s(", buf) == -1)
	return (trix(tmp, str));
      system(str);
      syscall_getproto(list, buffer);
      free(str);
      free(buffer);
      free(tmp);
      unlink("file");
      list = list->next;
    }
  return (SUCCESS);
}
