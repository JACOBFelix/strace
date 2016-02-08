#include <string.h>
#include "my_syscall.h"

t_arg	g_arg[] = {{"const void *", CONST_PTR},
		   {"void **", PTR},
		   {"void *", PTR},
		   {"const char *", CONST_CHAR_PTR},
		   {"char *", CHAR_PTR},
		   {"const int *", CONST_PTR},
		   {"int *", PTR},
		   {"sigset *", PTR},
		   {"time_t *", PTR},
		   {"const struct msghdr *", CONST_PTR},
		   {"const struct timeval *", CONST_PTR},
		   {"const struct gid_t *", CONST_PTR},
		   {"const sigset_t *",  CONST_PTR},
		   {"const struct timespec *", CONST_PTR},
		   {"const struct mmsghdr *", CONST_PTR},
		   {"const struct sigaction *", PTR_SIGACTION},
		   {"const struct iovec *", CONST_PTR},
		   {"const struct utimbuf *", CONST_PTR},
		   {"const struct sockaddr *", CONST_PTR},
		   {"const stack_t *", CONST_PTR},
		   {"const struct itimerval *", CONST_PTR},
		   {"const struct rlimit *", CONST_PTR},
		   {"const struct sigevent *", CONST_PTR},
		   {"const gid_t *", CONST_PTR},
		   {"const struct sched_param *", CONST_PTR},
		   {"const struct strbuff *", CONST_PTR},
		   {"const struct strbuf *", CONST_PTR},
		   {"const struct timezone *", CONST_PTR},
		   {"struct sched_param *", PTR},
		   {"struct linux_dirent *", PTR},
		   {"struct sembuf *", PTR},
		   {"struct io_event *", PTR},
		   {"struct kexec_segment *", PTR},
		   {"struct rusage *", PTR},
		   {"struct nfsctl_arg *", PTR},
		   {"struct mq_attr *", PTR},
		   {"struct timezone *", PTR},
		   {"struct msghdr *", PTR},
		   {"struct pollfd *", PTR},
		   {"struct timeval *", PTR},
		   {"struct itimerspec *", PTR},
		   {"struct epoll_event *", PTR},
		   {"struct linux_event *", PTR},
		   {"struct pollfd *", PTR},
		   {"struct stat *", PTR},
		   {"struct sigaction *", PTR_SIGACTION},
		   {"struct shmid_ds *", PTR},
		   {"struct msqid_ds *", PTR},
		   {"struct getcpu_cache *", PTR},
		   {"struct itimerval *", PTR},
		   {"struct mmsghdr *", PTR},
		   {"struct sysinfo *", PTR},
		   {"struct gid_t *", PTR},
		   {"struct ustat *", PTR},
		   {"struct statfs *", PTR},
		   {"struct iocb *", PTR},
		   {"struct sigevent *", PTR},
		   {"struct sockaddr *", PTR},
		   {"struct file_handle", PTR},
		   {"struct tms *", PTR},
		   {"struct timex *", PTR},
		   {"struct rlimit *", PTR},
		   {"struct timespec *", PTR},
		   {"struct utsname *", PTR},
		   {"sigset_t *", PTR},
		   {"struct kernel_sym *", PTR},
		   {"struct user_desc *", PTR},
		   {"struct __sysctl_args *", PTR},
		   {"union nfsctl_res *", PTR},
		   {"siginfo_t *", PTR},
		   {"fd_set *", PTR},
		   {"unsigned *", UNSIGNED_INT_PTR},
		   {"stack_t *", PTR},
		   {"loff_t *", PTR},
		   {"socklen_t *", PTR},
		   {"cpu_set_t *", PTR},
		   {"cap_user_header_t", PTR},
		   {"enum __ptrace_request", PTR},
		   {"aio_context_t", PTR},
		   {"unsigned int", UNSIGNED_INT},
		   {"unsigned long", UNSIGNED_LONG},
		   {"struct robust_list_head", STRUCT_ROBUST_LIST_HEAD},
		   {"const cap_user_data_t", CONST_CAP_USER_DATA_T},
		   {"unsigned", UNSIGNED_INT},
		   {"uint32_t", UNSIGNED_SHORT},
		   {"u64", UNSIGNED_LONG},
		   {"timer_t", TIMER_T},
		   {"mqd_t", INT},
		   {"idtype_t", UNSIGNED_INT},
		   {"dev_t", UNSIGNED_LONG},
		   {"uid_t", UNSIGNED_INT},
		   {"pid_t", UNSIGNED_INT},
		   {"gid_t", UNSIGNED_INT},
		   {"id_t", UNSIGNED_INT},
		   {"size_t", LONG},
		   {"key_t", INT},
		   {"mode_t", UNSIGNED_SHORT},
		   {"void", VOID},
		   {"ssize_t", LONG},
		   {"caddr_t", CHAR_PTR},
		   {"socklen_t", UNSIGNED_INT},
		   {"clockid_t", UNSIGNED_INT},
		   {"int pipefd[2]", INT_TAB},
		   {"const struct timeval times[2]", STRUCTTIMEVALTAB},
		   {"const struct timespec times[2]", STRUCTTIMESPECTIMES},
		   {"int (*fd)(void *)", FCT_PTR},
		   {"int", INT},
		   {"long", LONG},
		   {"nfds_t", UNSIGNED_LONG},
		   {"off_t", UNSIGNED_LONG},
		   {"off64_t", LONG},
		   {"cap_user_data_t", CAP_USER_DATA_T},
		   {"...", VARARG},
		   {NULL, 0}};

static int	parse_first_arg(t_list *list UNUSED,
				char *str UNUSED,
				int *arg UNUSED,
				int a)
{
  int		i;

  if (str == NULL)
    return (SUCCESS);
  while (*str == ' ' || *str == '\t')
    ++str;
  if (*str == 0)
    return (SUCCESS);
  i = -1;
  while (g_arg[++i].str != NULL && strncmp(g_arg[i].str,  str,
					   strlen(g_arg[i].str)) != 0)
    ;
  if (g_arg[i].str == NULL)
    return (SUCCESS);
  *arg = g_arg[i].type;
  return (parse_first_arg(list, strtok(NULL, "\n,"), ++arg, ++a));
  printf("%s\n", str);
}

int		parse_arg(t_list *list UNUSED,
			  char *str)
{
  char		*tmp;

  if ((tmp = strtok(str, "\n,")) == NULL)
    return (FAILURE);
  return (parse_first_arg(list, str,
			  &((t_syscall *)(list->data))->type_first_arg, 0));
}
