#include <string.h>
#include <stdio.h>
#include "strace.h"

int	main(int const ac UNUSED,
	     char const *const ag[] UNUSED,
	     char const *const env[])
{
  if (ac == 1)
    return (dprintf(2, "%s\n", NEED_ARG) - sizeof(NEED_ARG) - 1);
  if (strcmp(ag[1], "-p") == 0)
    return (trace_pid(ag[2]));
  return (trace_exec(ag, env));
}
