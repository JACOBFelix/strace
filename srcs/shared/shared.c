#include <string.h>
#include <stdio.h>
#include "shared.h"

ALWAYS_INLINE char	*my_concat(char const *const one,
				   char const *const two)
{
  char			*new;

  if ((new = malloc(sizeof(char) * (strlen(one) + strlen(two) + 1))) == NULL)
    return (NULL);
  strcpy(new, one);
  strcpy(new + strlen(one), two);
  return (new);
}

ALWAYS_INLINE int	my_error_line(char const *const msg,
				      char const *const line)
{
  dprintf(2, "%s\n%s\n", msg, line);
  return (FAILURE);
}

ALWAYS_INLINE int	my_perror(char const *const file,
				  char const *const func,
				  int const line,
				  char const *const msg)
{
  dprintf(2, "Error in file : %s\nFunction : %s\nLine : %d\nMessage : %s\n",
	 file, func, line, msg);
  perror(NULL);
  return (FAILURE);
}

ALWAYS_INLINE int	my_error(char const *const msg)
{
  dprintf(2, "%s\n", msg);
  return (FAILURE);
}
