#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_syscall.h"

int	check_first_second_line(FILE *const file,
				char *str,
				size_t *const size)
{
  if (getline(&str, size, file) == -1 || str == NULL ||
      strcmp(str, UNISTD_IFNDEF) != 0)
    return (my_perror(ERR, FIRST_LINE_ERR));
  free(str);
  str = NULL;
  *size = 0;
  if (getline(&str, size, file) == -1 || str == NULL ||
      strcmp(str, UNISTD_DEFINE) != 0)
    return (my_perror(ERR, SEC_LINE_ERR));
  free(str);
  str = NULL;
  *size = 0;
  return (SUCCESS);
}

static int	generat_new_syscall(t_list **list,
				    char const *const name,
				    char const *const opcode)
{
  t_syscall	*syscall;

  if ((syscall = malloc(sizeof(t_syscall))) == NULL)
    return (my_perror(ERR, MALLOC_ERR));
  memset(syscall, 0, sizeof(t_syscall));
  if ((syscall->name = strdup(name)) == NULL)
    return (my_perror(ERR, MALLOC_ERR));
  syscall->opcode = atoi(opcode);
  return (add_element(list, syscall));
}

static int	check_syscall_line(char const *const str,
				   t_list **list)
{
  char		*opcode;
  char		*name;
  char		*tmp;

  if (strcmp(str, EMPTY_LINE) == 0 || str[0] == 0)
      return (SUCCESS);
  if (strlen(str) < sizeof(BEGIN_LINE)
      || strncmp(str, BEGIN_LINE, sizeof(BEGIN_LINE) - 1) != 0)
    return (my_error_line(UNVALID_DEFINE, str));
  if ((opcode = strrchr(str, ' ')) == NULL || strlen(opcode) < 2)
    return (my_error_line(UNVALID_NOT_OP_CODE, str));
  if ((name = strchr(str, 'R')) == NULL || strlen(name) < 4)
    return (my_error_line(UNVALID_NOT_NAME, str));
  if ((tmp = strrchr(str, ' ')) == NULL || strlen(tmp) < 2)
    return (my_error_line(UNVALID_NOT_OP_CODE, str));
  *tmp = 0;
  name += 2;
  opcode += 1;
  return (generat_new_syscall(list, name, opcode));
}

ALWAYS_INLINE static int	check_double(t_list *const *const list)
{
  t_list			*tmp;
  t_list			*tmp2;
  int				i;

  if ((tmp = *list) == NULL)
    return (my_perror(ERR, NO_ELEMENT));
  while (tmp != NULL)
    {
      tmp2 = *list;
      i = 0;
      while (tmp2 != NULL)
	{
	  if ((strcmp(((t_syscall *)(tmp->data))->name,
		      ((t_syscall *)(tmp2->data))->name) == 0
	       || ((t_syscall *)(tmp->data))->opcode
	       == ((t_syscall *)(tmp2->data))->opcode))
	    ++i;
	  tmp2 = tmp2->next;
	}
      if (i != 1)
	return (my_error_line(ERR_DOUBLE_SYSCALL,
			      ((t_syscall *)(tmp->data))->name));
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int	check_line(FILE *const file,
		   char *str,
		   size_t *const size,
		   t_list **list)
{
  int	end;

  end = 0;
  while (getline(&str, size, file) != -1)
    {
      if (strcmp(str, LAST_LINE_ENDIF) == 0)
	{
	  ++end;
	  break ;
	}
      if (check_syscall_line(str, list) == FAILURE)
	return (FAILURE);
      free(str);
      *size = 0;
      str = NULL;
    }
  free(str);
  if (end == 0)
    return (my_error(LAST_LINE_INVALIDE));
  return (check_double(list));
}
