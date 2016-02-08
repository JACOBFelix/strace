#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my_syscall.h"

static int	end_main(FILE const *const file, int const output)
{
  if (fclose((FILE *)file) != 0)
    {
      if (close(output) == -1)
	my_perror(ERR, CLOSE_OUTPUT_FILE);
      return (my_perror(ERR, CLOSE_SYSCALL_FILE));
    }
  if (close(output) == -1)
    return (my_perror(ERR, CLOSE_OUTPUT_FILE));
  return (SUCCESS);
}

static int	start(FILE const *const file, int
		      const output UNUSED,
		      char const *const *env UNUSED)
{
  char		*str;
  size_t        size;
  t_list	*list;

  size = 0;
  str = NULL;
  list = NULL;
  if (check_first_second_line((FILE *const)file, str, &size) == FAILURE ||
      check_line((FILE *const)file, str, &size, &list) == FAILURE)
    return (FAILURE);
  handle_syscall(list);
  print(list, output);
  free_syscall(list);
  return (SUCCESS);
}

static int		follow_main(char const *const str,
				    char const *const *env)
{
  FILE	const *const	file = fopen(str, "r");
  int	const		output = creat("./includes/list_syscall.h",
				       O_TRUNC | S_IRUSR | S_IWUSR
				       | S_IRGRP | S_IROTH);

  if (file == NULL)
    {
      my_perror(ERR, SYSCALL_FILE_OPEN);
      if (output != -1 && close(output) == -1)
	my_perror(ERR, CLOSE_OUTPUT_FILE);
      return (FAILURE);
    }
  if (output == -1)
    {
      my_perror(ERR, ERR_CREAT_FILE);
      if (fclose((FILE *)file) != 0)
	my_perror(ERR, CLOSE_OUTPUT_FILE);
      return (FAILURE);
    }
  start(file, output, env);
  return (end_main(file, output));

}

int	main(int const ac,
	     char const *const *ag,
	     char const *const *env)
{
  if (ac == 1)
    return (follow_main("/usr/include/asm/unistd_64.h", env));
  return (follow_main(ag[1], env));
}
