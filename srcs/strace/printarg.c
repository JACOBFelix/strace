#include <stdio.h>
#include "strace.h"
#include "shared.h"

t_ret	g_tab[] = {{CHAR_PTR, &printcharptr},
		   {CONST_CHAR_PTR, &printcharptr},
		   {PTR, &printptr},
		   {CONST_PTR, &printptr},
		   {VARARG, &printvararg},
		   {INT_PTR, &printptr},
		   {UNSIGNED_INT, &printuint},
		   {INT, &printint},
		   {LONG, &printlong},
		   {UNSIGNED_LONG, &printulong},
		   {LONG_PTR, &printptr},
		   {UNSIGNED_LONG_PTR, &printptr},
		   {INT_TAB, &printinttab},
		   {FCT_PTR, &printptr},
		   {SHORT, &printshort},
		   {UNSIGNED_SHORT, &printushort},
		   {CAP_USER_DATA_T, &printulong},
		   {STRUCTTIMEVALTAB, &printtimevaltab},
		   {STRUCTTIMESPECTIMES, &printtimespectab},
		   {INT_TAB, &printinttab},
		   {FCT_PTR, &printptr},
		   {CAP_USER_DATA_T, &printcapuserdatat},
		   {0, NULL}};

static void	print_an_arg(int type UNUSED,
			     unsigned long long int reg UNUSED,
			     pid_t pid UNUSED,
			     int num,
			     t_callsys *sys)
{
  int		i;

  if (sys->opcode == 202 && num >= 3)
    return ;
  if (type != 0 && num != 0 && num != 7)
    dprintf(2, ", ");
  if (type == 0)
    return ;
  i = -1;
  while (g_tab[++i].type != 0)
    {
      if (g_tab[i].type == type)
	{
	  g_tab[i].fct(reg, pid);
	  return ;
	}
    }
  dprintf(2, "Unknown Arg");
}

void		print_arg(t_callsys * sys UNUSED,
			  struct user_regs_struct reg UNUSED,
			  pid_t pid UNUSED)
{
  dprintf(2, "(");
  print_an_arg(sys->type_first_arg, reg.rdi, pid, 0, sys);
  print_an_arg(sys->type_sec_arg, reg.rsi, pid, 1, sys);
  print_an_arg(sys->type_third_arg, reg.rdx, pid, 2, sys);
  print_an_arg(sys->type_fourth_arg, reg.r10, pid, 3, sys);
  print_an_arg(sys->type_fifth_arg, reg.r8, pid, 4, sys);
  print_an_arg(sys->type_six_arg, reg.r9, pid, 5, sys);
}
