#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include "strace.h"

ALWAYS_INLINE int	current(char const *const ag[] UNUSED,
				char const *const envp[])
{
  char			*env;
  char			*path;
  int			a;

  if ((env = getenv("PWD")) == NULL)
    return (dprintf(2, "%s\n", NO_ENV) - sizeof(NO_ENV) - 1 + FAILURE);
  if (asprintf(&path, "%s/%s", env, ag[1]) == -1)
    return (dprintf(2, "%s\n", MEMORY_ERR) - sizeof(MEMORY_ERR) - 1
	    + FAILURE);
  if (access(path, X_OK) == 0)
    {
      a = exec(path, ag + 1, envp);
      free(path);
      return (a);
    }
  free(path);
  return (dprintf(2, "%s\n", INV_ARG) - sizeof(INV_ARG) - 1 + FAILURE);
}

ALWAYS_INLINE int	path(char const *const ag[] UNUSED,
			     char const *const envp[])
{
  char			*env;
  char			*path;
  char			*tmp;
  int			a;

  if ((env = getenv("PATH")) == NULL)
    return (dprintf(2, "%s\n", NO_ENV) - sizeof(NO_ENV) - 1 + FAILURE);
  while ((tmp = strtok(env, ":")) != NULL)
    {
      if (asprintf(&path, "%s/%s", tmp, ag[1]) == -1)
	return (dprintf(2, "%s\n", MEMORY_ERR) - sizeof(MEMORY_ERR) - 1
		+ FAILURE);
      if (access(path, X_OK) == 0)
	{
	  a = exec(path, ag + 1, envp);
	  free(path);
	  return (a);
	}
      free(path);
      env = NULL;
    }
  return (dprintf(2, "%s\n", INV_ARG) - sizeof(INV_ARG) - 1 + FAILURE);
}

ALWAYS_INLINE int	trace_exec(char const *const ag[] UNUSED,
				   char const *const env[])
{
  if (ag[1][0] == '.')
    return (current(ag, env));
  else if (ag[1][0] != '/')
    return (path(ag, env));
  else if (access(ag[1], X_OK) == 0)
    return (exec(ag[1], ag + 1, env));
  return (dprintf(2, "%s\n", INV_ARG) - sizeof(INV_ARG) - 1 + FAILURE);
}
