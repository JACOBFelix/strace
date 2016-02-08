#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include "my_syscall.h"

ALWAYS_INLINE static char       *particular_case_cut_end(t_list *list,
							 int a,
							 char *buffer)
{
  if ((a = asprintf(&buffer, "2 %s", ((t_syscall *)(list->data))->name))
      == -1)
    {
      my_perror(ERR, MALLOC_ERR);
      return (NULL);
    }
  a = (int)strlen(buffer);
  --a;
  while (a > 0 && buffer[a] >= '0' && buffer[a] <= '9')
    --a;
  if (a == 0)
    return (buffer);
  buffer[a + 1] = 0;
  return (buffer);
}

ALWAYS_INLINE static char	*other_particular_case(t_list *list,
						       int a,
						       char *buffer)
{
  if (strcmp(((t_syscall *)(list->data))->name, "pselect6") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "signalfd4") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "pread64") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "pwrite64") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "getdents64") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "eventfd2") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "fadvise64") == 0 ||
      strcmp(((t_syscall *)(list->data))->name, "prlimit64") == 0)
    return (particular_case_cut_end(list, a, buffer));
  else if (strcmp(((t_syscall *)(list->data))->name, "getpmsg") == 0 ||
	   strcmp(((t_syscall *)(list->data))->name, "putpmsg") == 0)
    a = asprintf(&buffer, "3 %s", ((t_syscall *)(list->data))->name);
  else
    a = asprintf(&buffer, "2 %s", ((t_syscall *)(list->data))->name);
  if (a == -1)
    return (NULL);
  return (buffer);
}

char		*particular_case(t_list *list, int a)
{
  char		*buffer;

  if (strcmp(((t_syscall *)(list->data))->name, "epoll_ctl_old") == 0)
    a = asprintf(&buffer, "2 epoll_ctl");
  else if (strcmp(((t_syscall *)(list->data))->name, "epoll_wait_old") == 0)
    a = asprintf(&buffer, "2 epoll_wait");
  else if (strcmp(((t_syscall *)(list->data))->name, "newfstatat") == 0)
    a = asprintf(&buffer, "2 fstatat");
  else if (strcmp(((t_syscall *)(list->data))->name, "clock_adjtime") == 0)
    a = asprintf(&buffer, "adjtime");
  else if (strcmp(((t_syscall *)(list->data))->name, "getcwd") == 0)
    a = asprintf(&buffer, "getcwd");
  else if (strcmp(((t_syscall *)(list->data))->name, "fadvise64") == 0)
    a = asprintf(&buffer, "%s", "posix_fadvise");
  else if (strcmp(((t_syscall *)(list->data))->name, "rt_sigqueueinfo") == 0
	   || strcmp(((t_syscall *)(list->data))->name, "rt_tgsigqueueinfo") == 0)
    a = asprintf(&buffer, "%s", ((t_syscall *)(list->data))->name);
  else if (strncmp(((t_syscall *)(list->data))->name, "rt_", 3) == 0)
    a = asprintf(&buffer, "2 %s", ((t_syscall *)(list->data))->name + 3);
  if (a == -1)
    return (NULL);
  if (a != 0)
    return (buffer);
  return (other_particular_case(list, a, buffer));
}

