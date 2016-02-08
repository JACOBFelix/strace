#ifndef STRACE_H_
# define STRACE_H_

#include <unistd.h>
#include <sys/user.h>

typedef struct	s_callsys
{
  char	        *name;
  int	        opcode;
  int		ret_type;
  int		type_first_arg;
  int		type_sec_arg;
  int		type_third_arg;
  int		type_fourth_arg;
  int		type_fifth_arg;
  int		type_six_arg;
}		t_callsys;
void		moulitrixdecon(int *,
			       struct user_regs_struct,
			       pid_t);
int		trace_pid(char const *const);
int		num_syscall(unsigned long long int, pid_t);
void		my_wait(pid_t);
void		check_status(int, int);
void		printcapuserdatat(unsigned long long int, pid_t);
void		printvoid(unsigned long long int, pid_t);
void		printcapuserdata(unsigned long long int, pid_t);
void		printtimevaltab(unsigned long long int, pid_t);
void		printtimespectab(unsigned long long int, pid_t);
void		printinttab(unsigned long long int, pid_t);
void		printvararg(unsigned long long int, pid_t);
void	        printcharptr(unsigned long long int, pid_t);
void		printptr(unsigned long long int, pid_t);
void		printulong(unsigned long long int, pid_t);
void		printlong(unsigned long long int, pid_t);
void		printuint(unsigned long long int, pid_t);
void		printint(unsigned long long int, pid_t);
void		printchar(unsigned long long int, pid_t);
void		printuchar(unsigned long long int, pid_t);
void		printshort(unsigned long long int, pid_t);
void		printushort(unsigned long long int, pid_t);
void		print_arg(t_callsys *,
			  struct user_regs_struct,
			  pid_t);
void		print_ret(t_callsys const *const,
			  unsigned long long int,
			  pid_t);
int		exec(char const *,
		     char const *const [],
		     char const *const []);
int		current(char const *const [],
			char const *const []);
int		trace_exec(char const *const [],
			   char const *const []);
int		path(char const *const [],
		     char const *const []);
# define INV_ARG "Argument is not valide"
# define MEMORY_ERR "Not enough memory to execute strace."
# define INV_PATH "Path is invalid."
# define CMD_NT_FND "Invalid command : Not found."
# define NO_ENV "Env is not defined."
# define UNDEF_PID "-p [PID] : PID is not in progress."
# define NEED_ARG "Need a executable to trace or -p [PID]."
# define SUCCESS 0
# define FAILURE 1
# define UNUSED __attribute__((unused))
# define ALWAYS_INLINE __attribute__((always_inline)) inline
# define ERR __FILE__, __func__, __LINE__

#endif /* !STRACE_H_ */
