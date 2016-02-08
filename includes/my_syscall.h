#ifndef MY_SYSCALL_H_
# define MY_SYSCALL_H_

#include <dirent.h>
#include <stdio.h>
#include "shared.h"

typedef struct	s_man
{
  char		*path;
  char		*name;
  char		*abs_name;
}		t_man;

int	syscall_getproto(t_list *,
			 char *);
char	*particular_case(t_list *,
			 int);
int	handle_syscall(t_list *);
int	handle_man_path(char *,
			t_list **,
			t_list *);
int	handle_man(t_list **,
		   t_list *,
		   struct dirent *,
		   char *);
void	print(t_list *,
	      int const);
void	free_syscall(t_list *);
void	free_man(t_list *);
int	check_first_second_line(FILE *,
				char *,
				size_t *);
int	check_line(FILE *,
		   char *,
		   size_t *,
		   t_list **);
int	add_element(t_list **, void *);
int	recup_man(t_list **, t_list *);
void	sort_man(t_list *,
		 t_list **);
int	parse_unistd(t_list *,
		     t_list **);
int	parse_prototype(t_list *);
int	parse_ret_normal(char *,
			 char *,
			 t_list *);
int     parse_arg(t_list *,
		  char *);
# define FIRST_LINE_1 "/*\n** strace_syscall.h for strace_syscall "
# define FIRST_LINE FIRST_LINE_1"in /home/jacob_f/rendu/AUSP_strace\n"
# define SECOND_LINE FIRST_LINE"**\n"
# define THIRD_LINE SECOND_LINE"** Made by felix jacob\n"
# define FOU_LINE THIRD_LINE"** Login   <jacob_f@epitech.net\n**\n** "
# define SIX_LINE FOU_LINE"Started on Mon May 4 42:42:42 4242 felix jacob\n*"
# define SE_LINE SIX_LINE"* Last update Mon May 4 42:42:42 4242 felix jacob\n"
# define END_COMMENT SE_LINE"*/\n"
# define EMACS_HEADER END_COMMENT"\n#ifndef LIST_SYSCALL_H_\n"
# define HEAD EMACS_HEADER"# define LIST_SYSCALL_H_\n"
# define DEFINE "# define LIST_SYSCALL_H_"
# define HEAD1 HEAD"\nstatic t_callsys	g_arg[] = {"
# define ENDIF "#endif /* !LIST_SYSCALL_H_ */"
# define INIT 0
# define PROTO_ERR "Error can't get a syscall prototype"
# define ERR_OPEN "Error can't open the file where syscall prototype"
# define ERR_READ "Error can't read the file where syscall prototype"
# define FILE_GETLINE ERR_READ" is stored"
# define ERR_OPEN_FILE ERR_OPEN" is stored"
# define STAT_ERR "Error with stat : Can't determined a status"
# define SCANDIR_ERR "Error with scan dir for repertory the man"
# define ERR_CLOSEDIR1 "Error with closedir can\'t close a man"
# define ERR_CLOSEDIR ERR_CLOSEDIR1" directory opened"
# define ERR_OPENDIR "Error with opendir can\'t open a man directory"
# define MANPATH_INV "Error env variable MANPATH is invalide"
# define MANPATH_ERR "Error variable MANPATH is not set in envirronement"
# define ERR_SYS "Error two syscall has been repertoried with the same name"
# define ERR_DOUBLE_SYSCALL ERR_SYS" or the same opcode"
# define ERR_ANY "Error any sycall is reperoried in "
# define NO_ELEMENT ERR_ANY"/usr/include/asm/unistd_64.h"
# define MALLOC_ERR "Error with memory allocation."
# define EMPTY_LINE "\n"
# define UNISTD_DEFINE "#define _ASM_X86_UNISTD_64_H 1\n"
# define UNISTD_IFNDEF "#ifndef _ASM_X86_UNISTD_64_H\n"
# define LAST_LINE_ENDIF "#endif /* _ASM_X86_UNISTD_64_H */\n"
# define BEGIN_LINE "#define __NR_"
# define ERR_VAL_SYS "Error value of the syscall "
# define UNVALID_NOT_OP_CODE ERR_VAL_SYS"defined is not precised"
# define UNVALID_NOT_NAME "Error name of the syscall defined is not precised"
# define UNVA_DEF "Error on following line should begin with"
# define UNVALID_DEFINE UNVA_DEF" #define __NR_"
# define ERR_FIRST "Error : first line of /usr/include/asm/unistd_64.h"
# define FIRST_LINE_ERR ERR_FIRST" is not correct."
# define ERR_SEC "Error : second line of /usr/include/asm/unistd_64.h"
# define SEC_LINE_ERR ERR_SEC" is not correct."
# define ERR_LAST "Error : last line of /usr/include"
# define LAST_LINE_INVALIDE ERR_LAST"/asm/unistd_64.h is invalide."
# define SYSCALL_FILE_OPEN "Can't open the file /usr/include/asm/unistd_64.h"
# define CANTCLOSE "Can't close the file "
# define CLOSE_SYSCALL_FILE CANTCLOSE"/usr/include/asm/unistd_64.h"
# define CLOSE_OUTPUT_FILE "Can't close the file ./includes/list_syscall.h"
# define ERR_CREAT_FILE "Can't creat the file ./includes/list_syscall.h"
# define ERR_FILE_OPEN_UNI "Error can't open file /usr/include/unistd.h"

#endif /* !MY_SYSCALL_H_ */
