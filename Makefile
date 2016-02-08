##
## Makefile for Makefile in /home/jacob_f/rendu/AUSP_strace
## 
## Made by felix jacob
## Login   <jacob_f@epitech.net>
## 
## Started on  Tue Apr 28 21:23:59 2015 felix jacob
## Last update Sun May 17 23:10:11 2015 felix jacob
##

CC=		gcc

RM=		rm -rf

NAME=		strace

DIR=		./srcs

DIRTEST=	./unit_test

DIRSTRACE=	$(DIR)/strace

DIRSYSCALL=	$(DIR)/syscall

DIRSHARED=	$(DIR)/shared

SRCS=		$(DIRSTRACE)/main.c \
		$(DIRSTRACE)/path.c \
		$(DIRSTRACE)/exec.c \
		$(DIRSTRACE)/print_type.c \
		$(DIRSTRACE)/print_type2.c \
		$(DIRSTRACE)/print_type3.c \
		$(DIRSTRACE)/print_type4.c \
		$(DIRSTRACE)/print_ret.c \
		$(DIRSTRACE)/printarg.c \
		$(DIRSTRACE)/status.c \
		$(DIRSTRACE)/syscall.c \
		$(DIRSTRACE)/optionp.c \
		$(DIRSHARED)/shared.c

OBJS=		$(SRCS:.c=.o)

CFLAGS+=	-Wall -W -Wextra -Werror -I ./includes -O3

SRCSSYSCALL=	$(DIRSYSCALL)/main.c \
		$(DIRSYSCALL)/check.c \
		$(DIRSYSCALL)/list.c \
		$(DIRSYSCALL)/handle_syscall.c \
		$(DIRSYSCALL)/particular_syscall.c \
		$(DIRSYSCALL)/getproto.c \
		$(DIRSYSCALL)/parse_sys_ret.c \
		$(DIRSYSCALL)/parse_prototype.c \
		$(DIRSYSCALL)/parse_arg.c \
		$(DIRSYSCALL)/print.c \
		$(DIRSHARED)/shared.c

OBJSSYSCALL=	$(SRCSSYSCALL:.c=.o)

NAMESYSCALL=	generat_sys_file

NASMFLAGS=	-f elf64


SRCSTEST2=	$(DIRTEST)/testsegfaultasm.asm

OBJSTEST2=	$(SRCSTEST2:.asm=.o)

SRCSTEST3=	$(DIRTEST)/testinvalidsyscall.asm

OBJSTEST3=	$(SRCSTEST3:.asm=.o)

SRCSTEST4=	$(DIRTEST)/testsegfaultc.c

OBJSTEST4=	$(SRCSTEST4:.c=.o)

TEST2=		test2

TEST3=		test3

TEST4=		test4

%.o:		%.c
		@printf "[\033[0;32mCompiled\033[0m] % 35s\n" $< 
		@$(CC) -c -o $@ $< $(CFLAGS)

all:		$(NAMESYSCALL) $(NAME) $(TEST2) $(TEST3) $(TEST4)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
		@printf "[\033[0;34mAssembled\033[0m] % 34s\n" $(NAME) | tr ' ' '.' 

$(NAMESYSCALL):	$(OBJSSYSCALL)
		@$(CC) $(OBJSSYSCALL) -o $(NAMESYSCALL) $(CFLAGS)
		@printf "[\033[0;34mAssembled\033[0m] % 34s\n" $(NAMESYSCALL) | tr ' ' '.' 
		@./generat_sys_file


$(TEST2):
		nasm $(NASMFLAGS) $(SRCSTEST2)
		ld $(OBJSTEST2) -o $(TEST2)

$(TEST3):
		nasm $(NASMFLAGS) $(SRCSTEST3)
		ld $(OBJSTEST3) -o $(TEST3)

$(TEST4):	$(OBJSTEST4)
		@$(CC) $(OBJSTEST4) -o $(TEST4) $(CFLAGS)
		@printf "[\033[0;34mAssembled\033[0m] % 34s\n" $(TEST4) | tr ' ' '.' 

clean:
		@$(RM) $(OBJS)
		@printf "[\033[0;31mDeleted\033[0m] % 36s\n" $(OBJS) | tr ' ' '.'
		@$(RM) $(OBJSSYSCALL)
		@printf "[\033[0;31mDeleted\033[0m] % 36s\n" $(OBJSSYSCALL) | tr ' ' '.'
		@$(RM) $(OBJSTEST2)
		@printf "[\033[0;31mDeleted\033[0m] % 36s\n" $(OBJSTEST2) | tr ' ' '.'
		@$(RM) $(OBJSTEST3)
		@printf "[\033[0;31mDeleted\033[0m] % 36s\n" $(OBJSTEST3) | tr ' ' '.'
		@$(RM) $(OBJSTEST4)
		@printf "[\033[0;31mDeleted\033[0m] % 36s\n" $(OBJSTEST4) | tr ' ' '.'



fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;35mRemoved\033[0m] % 36s\n" $(NAME) | tr ' ' '.'
		@$(RM) $(NAMESYSCALL)
		@printf "[\033[0;35mRemoved\033[0m] % 36s\n" $(NAMESYSCALL) | tr ' ' '.'
		@$(RM) $(TEST2)
		@printf "[\033[0;35mRemoved\033[0m] % 36s\n" $(TEST2) | tr ' ' '.'
		@$(RM) $(TEST3)
		@printf "[\033[0;35mRemoved\033[0m] % 36s\n" $(TEST3) | tr ' ' '.'
		@$(RM) $(TEST4)
		@printf "[\033[0;35mRemoved\033[0m] % 36s\n" $(TEST4) | tr ' ' '.'

re:		fclean all

.PHONY:		all clean fclean re
