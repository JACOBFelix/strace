#ifndef SHARED_H_
# define SHARED_H_

#include <unistd.h>

typedef struct	s_syscall
{
  char		*name;
  char		*proto;
  int		man_linker;
  int		opcode;
  int		ret_type;
  int		nm_arg;
  int		type_first_arg;
  int		type_sec_arg;
  int		type_third_arg;
  int		type_fourth_arg;
  int		type_fifth_arg;
  int		type_sixth_arg;
}		t_syscall;

typedef struct	s_sys
{
  char		*name;
  int		type_ret;
  int		nb_arg;
  int		type_first_arg;
  int		type_second_arg;
  int		type_third_arg;
  int		type_fourth_arg;
  int		type_fifth_arg;
  int		type_sixth_arg;
}		t_sys;
typedef struct s_list	t_list;

typedef struct	s_arg
{
  char		*str;
  int		type;
}		t_arg;
struct	s_list
{
  t_list	*next;
  t_list	*prev;
  void		*data;
};

typedef struct	s_data
{
  char	        *str;
  int		value;
}		t_data;

typedef struct			s_ret
{
  int				type;
  void				(*fct)(unsigned long long int, pid_t);
}				t_ret;

char	*my_concat(char const *const,
		  char const *const);
int	my_error3(char const *const,
		  char const *const,
		  char const *const);
int	my_error_line(char const *const,
		      char const *const);
int	my_error(char const *const);
int	my_perror(char const *const,
		  char const *const,
		  int const,
		  char const *const);

# define ALWAYS_INLINE __attribute__((always_inline)) inline
# define ERR __FILE__, __func__, __LINE__
# define UNUSED __attribute__((unused))
# define FAILURE 1
# define SUCCESS 0
# define CRITIC -1
# define VOID 4142
# define GENERIC_PTR 4242
# define NOTHING 0
# define INT8PTR 101
# define INT8 1
# define UINT8PTR 102
# define UINT8 2
# define INT16PTR 103
# define INT16 3
# define UINT16PTR 104
# define UINT16 4
# define INT32PTR 105
# define INT32 5
# define UINT32PTR 106
# define UINT32 6
# define INT64PTR 107
# define INT64 7
# define UINT64PTR 108
# define UINT64 8
# define STRUCT_PTR 9
# define PID_T INT32
# define KEY_SERIAL_T INT16
# define SSIZE_T UINT64
# define UID_T UINT32
# define MODE_T UINT16
# define GID_T UINT32
# define TIME_T INT64
# define CLOCK_T UINT64
# define OFF_T INT64
# define MQD_T INT32
# define CADDR_T GENERIC_PTR
# define CHAR_PTR 1
# define CONST_CHAR_PTR 2
# define CONST_PTR 3
# define PTR 4
# define VARARG 5
# define INT 6
# define INT_PTR 7
# define UNSIGNED_INT 8
# define UNSIGNED_INT_PTR 9
# define LONG 10
# define LONG_PTR 11
# define UNSIGNED_LONG 12
# define UNSIGNED_LONG_PTR 13
# define INT_TAB 14
# define FCT_PTR 15
# define SHORT 16
# define UNSIGNED_SHORT 17
# define SHORT_PTR 18
# define UNIGNED_SHORT_PTR 19
# define PTR_SIGACTION 20
# define TIMER_T 99
# define STRUCT_ROBUST_LIST_HEAD 150
# define STRUCTTIMEVALTAB 142
# define STRUCTTIMESPECTIMES 143
# define CONST_CAP_USER_DATA_T 199
# define CAP_USER_DATA_T 198
# define UNKNOWN 9999

#endif /* !SHARED_H_ */
