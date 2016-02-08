#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_syscall.h"

ALWAYS_INLINE static int	end_parse_ret(t_list *list UNUSED,
					      int i UNUSED,
					      char *proto_dup UNUSED)
{
  char				*name;
  char				*tmp;

  if ((tmp = strdup(((t_syscall *)(list->data))->proto)) == NULL)
    return (my_perror(ERR, MALLOC_ERR));
  ((t_syscall *)(list->data))->ret_type = i;
  if ((name = strtok(NULL, " \t\n,()")) == NULL)
    {
      free(tmp);
      return (FAILURE);
    }
  if (name[0] == '*')
    ((t_syscall *)(list->data))->ret_type += 100;
  if (strchr(tmp, '(') == NULL || strchr(tmp, ')') == NULL)
    {
      free(tmp);
      return (FAILURE);
    }
  name = strchr(tmp, ')');
  *name = 0;
  i = (int)((long)(strchr(tmp, '(') - (long)(tmp)));
  parse_arg(list, tmp + 1 + (int)((long)(strchr(tmp, '(')) - (long)(tmp)));
  free(tmp);
  return (SUCCESS);
}

ALWAYS_INLINE int	parse_ret_normal(char *ret UNUSED,
					 char *proto_dup UNUSED,
					 t_list *list UNUSED)
{
  int	        	i;
  static const t_data	data[] = {{"unsigned int", UINT32},
				  {"int", INT32},
				  {"long", INT64},
				  {"char", INT8},
				  {"pid_t", PID_T},
				  {"key_serial_t", KEY_SERIAL_T},
				  {"ssize_t", SSIZE_T},
				  {"uid_t", UID_T},
				  {"mode_t", MODE_T},
				  {"gid_t", GID_T},
				  {"time_t", TIME_T},
				  {"clock_t", CLOCK_T},
				  {"off_t", OFF_T},
				  {"mqd_t", MQD_T},
				  {"caddr_t", GENERIC_PTR},
				  {"size_t", UINT32},
				  {"void", VOID},
				  {NULL, 0}};

  i = -1;
  while (data[++i].str != NULL)
    if (strcmp(ret, data[i].str) == 0)
      return (end_parse_ret(list, data[i].value, proto_dup));
  return (SUCCESS);
}
