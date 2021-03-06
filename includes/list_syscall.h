/*
** strace_syscall.h for strace_syscall in /home/jacob_f/rendu/AUSP_strace
**
** Made by felix jacob
** Login   <jacob_f@epitech.net
**
** Started on Mon May 4 42:42:42 4242 felix jacob
** Last update Mon May 4 42:42:42 4242 felix jacob
*/

#ifndef LIST_SYSCALL_H_
# define LIST_SYSCALL_H_

static t_callsys	g_arg[] = {{"read", 0, 8, 6, 4, 10,
		                    0, 0, 0},
		                   {"write", 1, 8, 6, 3, 10,
		                    0, 0, 0},
		                   {"open", 2, 5, 2, 6, 0,
		                    0, 0, 0},
		                   {"close", 3, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"stat", 4, 5, 2, 4, 0,
		                    0, 0, 0},
		                   {"fstat", 5, 5, 6, 4, 0,
		                    0, 0, 0},
		                   {"lstat", 6, 5, 2, 4, 0,
		                    0, 0, 0},
		                   {"poll", 7, 5, 4, 12, 6,
		                    0, 0, 0},
		                   {"lseek", 8, 7, 6, 12, 6,
		                    0, 0, 0},
		                   {"mmap", 9, 4242, 4, 10, 6,
		                    6, 6, 12},
		                   {"mprotect", 10, 5, 4, 10, 6,
		                    0, 0, 0},
		                   {"munmap", 11, 5, 4, 10, 0,
		                    0, 0, 0},
		                   {"brk", 12, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"rt_sigaction", 13, 5, 6, 20, 20,
		                    0, 0, 0},
		                   {"rt_sigprocmask", 14, 5, 6, 3, 4,
		                    0, 0, 0},
		                   {"rt_sigreturn", 15, 5, 12, 0, 0,
		                    0, 0, 0},
		                   {"ioctl", 16, 5, 6, 6, 5,
		                    0, 0, 0},
		                   {"pread64", 17, 8, 6, 4, 10,
		                    12, 0, 0},
		                   {"pwrite64", 18, 8, 6, 3, 10,
		                    12, 0, 0},
		                   {"readv", 19, 8, 6, 3, 6,
		                    0, 0, 0},
		                   {"writev", 20, 8, 6, 3, 6,
		                    0, 0, 0},
		                   {"access", 21, 5, 2, 6, 0,
		                    0, 0, 0},
		                   {"pipe", 22, 5, 14, 0, 0,
		                    0, 0, 0},
		                   {"select", 23, 5, 6, 4, 4,
		                    4, 4, 0},
		                   {"sched_yield", 24, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"mremap", 25, 4242, 4, 10, 10,
		                    6, 5, 0},
		                   {"msync", 26, 5, 4, 10, 6,
		                    0, 0, 0},
		                   {"mincore", 27, 5, 4, 10, 8,
		                    0, 0, 0},
		                   {"madvise", 28, 5, 4, 10, 6,
		                    0, 0, 0},
		                   {"shmget", 29, 5, 6, 10, 6,
		                    0, 0, 0},
		                   {"shmat", 30, 4242, 6, 3, 6,
		                    0, 0, 0},
		                   {"shmctl", 31, 5, 6, 6, 4,
		                    0, 0, 0},
		                   {"dup", 32, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"dup2", 33, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"pause", 34, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"nanosleep", 35, 5, 3, 4, 0,
		                    0, 0, 0},
		                   {"getitimer", 36, 5, 6, 4, 0,
		                    0, 0, 0},
		                   {"alarm", 37, 6, 8, 0, 0,
		                    0, 0, 0},
		                   {"setitimer", 38, 5, 6, 3, 4,
		                    0, 0, 0},
		                   {"getpid", 39, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"sendfile", 40, 8, 6, 6, 12,
		                    10, 0, 0},
		                   {"socket", 41, 5, 6, 6, 6,
		                    0, 0, 0},
		                   {"connect", 42, 5, 6, 3, 8,
		                    0, 0, 0},
		                   {"accept", 43, 5, 6, 4, 4,
		                    0, 0, 0},
		                   {"sendto", 44, 8, 6, 3, 10,
		                    6, 3, 8},
		                   {"recvfrom", 45, 8, 6, 4, 10,
		                    6, 4, 4},
		                   {"sendmsg", 46, 8, 6, 3, 6,
		                    0, 0, 0},
		                   {"recvmsg", 47, 8, 6, 4, 6,
		                    0, 0, 0},
		                   {"shutdown", 48, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"bind", 49, 5, 6, 3, 8,
		                    0, 0, 0},
		                   {"listen", 50, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"getsockname", 51, 5, 6, 4, 4,
		                    0, 0, 0},
		                   {"getpeername", 52, 5, 6, 4, 4,
		                    0, 0, 0},
		                   {"socketpair", 53, 5, 6, 6, 6,
		                    6, 0, 0},
		                   {"setsockopt", 54, 5, 6, 6, 6,
		                    3, 8, 0},
		                   {"getsockopt", 55, 5, 6, 6, 6,
		                    4, 4, 0},
		                   {"clone", 56, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"fork", 57, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"vfork", 58, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"execve", 59, 5, 2, 1, 1,
		                    0, 0, 0},
		                   {"exit", 60, 4142, 6, 0, 0,
		                    0, 0, 0},
		                   {"wait4", 61, 5, 8, 4, 6,
		                    4, 0, 0},
		                   {"kill", 62, 5, 8, 6, 0,
		                    0, 0, 0},
		                   {"uname", 63, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"semget", 64, 5, 6, 6, 6,
		                    0, 0, 0},
		                   {"semop", 65, 5, 6, 4, 8,
		                    0, 0, 0},
		                   {"semctl", 66, 5, 6, 6, 6,
		                    5, 0, 0},
		                   {"shmdt", 67, 5, 3, 0, 0,
		                    0, 0, 0},
		                   {"msgget", 68, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"msgsnd", 69, 5, 6, 3, 10,
		                    6, 0, 0},
		                   {"msgrcv", 70, 8, 6, 4, 10,
		                    10, 6, 0},
		                   {"msgctl", 71, 5, 6, 6, 4,
		                    0, 0, 0},
		                   {"fcntl", 72, 5, 6, 6, 5,
		                    0, 0, 0},
		                   {"flock", 73, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"fsync", 74, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"fdatasync", 75, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"truncate", 76, 5, 2, 12, 0,
		                    0, 0, 0},
		                   {"ftruncate", 77, 5, 6, 12, 0,
		                    0, 0, 0},
		                   {"getdents", 78, 5, 8, 4, 8,
		                    0, 0, 0},
		                   {"getcwd", 79, 101, 1, 10, 0,
		                    0, 0, 0},
		                   {"chdir", 80, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"fchdir", 81, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"rename", 82, 5, 2, 2, 0,
		                    0, 0, 0},
		                   {"mkdir", 83, 5, 2, 17, 0,
		                    0, 0, 0},
		                   {"rmdir", 84, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"creat", 85, 5, 2, 17, 0,
		                    0, 0, 0},
		                   {"link", 86, 5, 2, 2, 0,
		                    0, 0, 0},
		                   {"unlink", 87, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"symlink", 88, 5, 2, 2, 0,
		                    0, 0, 0},
		                   {"readlink", 89, 8, 2, 1, 10,
		                    0, 0, 0},
		                   {"chmod", 90, 5, 2, 17, 0,
		                    0, 0, 0},
		                   {"fchmod", 91, 5, 6, 17, 0,
		                    0, 0, 0},
		                   {"chown", 92, 5, 2, 8, 8,
		                    0, 0, 0},
		                   {"fchown", 93, 5, 6, 8, 8,
		                    0, 0, 0},
		                   {"lchown", 94, 5, 2, 8, 8,
		                    0, 0, 0},
		                   {"umask", 95, 4, 17, 0, 0,
		                    0, 0, 0},
		                   {"gettimeofday", 96, 5, 4, 4, 0,
		                    0, 0, 0},
		                   {"getrlimit", 97, 5, 6, 4, 0,
		                    0, 0, 0},
		                   {"getrusage", 98, 5, 6, 4, 0,
		                    0, 0, 0},
		                   {"sysinfo", 99, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"times", 100, 8, 4, 0, 0,
		                    0, 0, 0},
		                   {"ptrace", 101, 7, 4, 8, 4,
		                    4, 0, 0},
		                   {"getuid", 102, 6, 4142, 0, 0,
		                    0, 0, 0},
		                   {"syslog", 103, 5, 6, 1, 6,
		                    0, 0, 0},
		                   {"getgid", 104, 6, 4142, 0, 0,
		                    0, 0, 0},
		                   {"setuid", 105, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"setgid", 106, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"geteuid", 107, 6, 4142, 0, 0,
		                    0, 0, 0},
		                   {"getegid", 108, 6, 4142, 0, 0,
		                    0, 0, 0},
		                   {"setpgid", 109, 5, 8, 8, 0,
		                    0, 0, 0},
		                   {"getppid", 110, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"getpgrp", 111, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"setsid", 112, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"setreuid", 113, 5, 8, 8, 0,
		                    0, 0, 0},
		                   {"setregid", 114, 5, 8, 8, 0,
		                    0, 0, 0},
		                   {"getgroups", 115, 5, 6, 8, 0,
		                    0, 0, 0},
		                   {"setgroups", 116, 5, 10, 3, 0,
		                    0, 0, 0},
		                   {"setresuid", 117, 5, 8, 8, 8,
		                    0, 0, 0},
		                   {"getresuid", 118, 5, 8, 8, 8,
		                    0, 0, 0},
		                   {"setresgid", 119, 5, 8, 8, 8,
		                    0, 0, 0},
		                   {"getresgid", 120, 5, 8, 8, 8,
		                    0, 0, 0},
		                   {"getpgid", 121, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"setfsuid", 122, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"setfsgid", 123, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"getsid", 124, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"capget", 125, 5, 4, 198, 0,
		                    0, 0, 0},
		                   {"capset", 126, 5, 4, 199, 0,
		                    0, 0, 0},
		                   {"rt_sigpending", 127, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"rt_sigtimedwait", 128, 5, 3, 4, 3,
		                    0, 0, 0},
		                   {"rt_sigqueueinfo", 129, 5, 8, 6, 4,
		                    0, 0, 0},
		                   {"rt_sigsuspend", 130, 5, 3, 0, 0,
		                    0, 0, 0},
		                   {"sigaltstack", 131, 5, 3, 4, 0,
		                    0, 0, 0},
		                   {"utime", 132, 5, 2, 3, 0,
		                    0, 0, 0},
		                   {"mknod", 133, 5, 2, 17, 12,
		                    0, 0, 0},
		                   {"uselib", 134, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"personality", 135, 5, 12, 0, 0,
		                    0, 0, 0},
		                   {"ustat", 136, 5, 12, 4, 0,
		                    0, 0, 0},
		                   {"statfs", 137, 5, 2, 4, 0,
		                    0, 0, 0},
		                   {"fstatfs", 138, 5, 6, 4, 0,
		                    0, 0, 0},
		                   {"sysfs", 139, 5, 6, 2, 0,
		                    0, 0, 0},
		                   {"getpriority", 140, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"setpriority", 141, 5, 6, 6, 6,
		                    0, 0, 0},
		                   {"sched_setparam", 142, 5, 8, 3, 0,
		                    0, 0, 0},
		                   {"sched_getparam", 143, 5, 8, 4, 0,
		                    0, 0, 0},
		                   {"sched_setscheduler", 144, 5, 8, 6, 3,
		                    0, 0, 0},
		                   {"sched_getscheduler", 145, 5, 8, 0, 0,
		                    0, 0, 0},
		                   {"sched_get_priority_max", 146, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"sched_get_priority_min", 147, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"sched_rr_get_interval", 148, 5, 8, 4, 0,
		                    0, 0, 0},
		                   {"mlock", 149, 5, 3, 10, 0,
		                    0, 0, 0},
		                   {"munlock", 150, 5, 3, 10, 0,
		                    0, 0, 0},
		                   {"mlockall", 151, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"munlockall", 152, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"vhangup", 153, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"modify_ldt", 154, 5, 6, 4, 12,
		                    0, 0, 0},
		                   {"pivot_root", 155, 5, 2, 2, 0,
		                    0, 0, 0},
		                   {"_sysctl", 156, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"prctl", 157, 5, 6, 12, 12,
		                    12, 12, 0},
		                   {"arch_prctl", 158, 5, 6, 12, 0,
		                    0, 0, 0},
		                   {"adjtimex", 159, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"setrlimit", 160, 5, 6, 3, 0,
		                    0, 0, 0},
		                   {"chroot", 161, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"sync", 162, 4142, 4142, 0, 0,
		                    0, 0, 0},
		                   {"acct", 163, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"settimeofday", 164, 5, 3, 3, 0,
		                    0, 0, 0},
		                   {"mount", 165, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"umount2", 166, 5, 2, 6, 0,
		                    0, 0, 0},
		                   {"swapon", 167, 5, 2, 6, 0,
		                    0, 0, 0},
		                   {"swapoff", 168, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"reboot", 169, 5, 6, 6, 6,
		                    4, 0, 0},
		                   {"sethostname", 170, 5, 2, 10, 0,
		                    0, 0, 0},
		                   {"setdomainname", 171, 5, 2, 10, 0,
		                    0, 0, 0},
		                   {"iopl", 172, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"ioperm", 173, 5, 12, 12, 6,
		                    0, 0, 0},
		                   {"create_module", 174, 4242, 2, 10, 0,
		                    0, 0, 0},
		                   {"init_module", 175, 5, 4, 12, 2,
		                    0, 0, 0},
		                   {"delete_module", 176, 5, 2, 6, 0,
		                    0, 0, 0},
		                   {"get_kernel_syms", 177, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"query_module", 178, 5, 2, 6, 4,
		                    10, 10, 0},
		                   {"quotactl", 179, 5, 6, 2, 6,
		                    1, 0, 0},
		                   {"nfsservctl", 180, 7, 6, 4, 4,
		                    0, 0, 0},
		                   {"getpmsg", 181, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"putpmsg", 182, 5, 6, 3, 3,
		                    6, 6, 0},
		                   {"afs_syscall", 183, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"tuxcall", 184, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"security", 185, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"gettid", 186, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"readahead", 187, 8, 6, 10, 10,
		                    0, 0, 0},
		                   {"setxattr", 188, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"lsetxattr", 189, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"fsetxattr", 190, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"getxattr", 191, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"lgetxattr", 192, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"fgetxattr", 193, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"listxattr", 194, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"llistxattr", 195, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"flistxattr", 196, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"removexattr", 197, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"lremovexattr", 198, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"fremovexattr", 199, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"tkill", 200, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"time", 201, 7, 4, 0, 0,
		                    0, 0, 0},
		                   {"futex", 202, 5, 4, 6, 6,
		                    3, 4, 6},
		                   {"sched_setaffinity", 203, 5, 8, 10, 4,
		                    0, 0, 0},
		                   {"sched_getaffinity", 204, 5, 8, 10, 4,
		                    0, 0, 0},
		                   {"set_thread_area", 205, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"io_setup", 206, 5, 8, 4, 0,
		                    0, 0, 0},
		                   {"io_destroy", 207, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"io_getevents", 208, 5, 4, 10, 10,
		                    4, 4, 0},
		                   {"io_submit", 209, 5, 4, 10, 4,
		                    0, 0, 0},
		                   {"io_cancel", 210, 5, 4, 4, 4,
		                    0, 0, 0},
		                   {"get_thread_area", 211, 5, 4, 0, 0,
		                    0, 0, 0},
		                   {"lookup_dcookie", 212, 5, 12, 1, 10,
		                    0, 0, 0},
		                   {"epoll_create", 213, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"epoll_ctl_old", 214, 5, 6, 6, 6,
		                    4, 0, 0},
		                   {"epoll_wait_old", 215, 5, 6, 4, 6,
		                    6, 0, 0},
		                   {"remap_file_pages", 216, 5, 4, 10, 6,
		                    10, 6, 0},
		                   {"getdents64", 217, 5, 8, 4, 8,
		                    0, 0, 0},
		                   {"set_tid_address", 218, 7, 4, 0, 0,
		                    0, 0, 0},
		                   {"restart_syscall", 219, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"semtimedop", 220, 5, 6, 4, 8,
		                    4, 0, 0},
		                   {"fadvise64", 221, 5, 6, 12, 12,
		                    6, 0, 0},
		                   {"timer_create", 222, 5, 8, 4, 99,
		                    0, 0, 0},
		                   {"timer_settime", 223, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"timer_gettime", 224, 5, 99, 4, 0,
		                    0, 0, 0},
		                   {"timer_getoverrun", 225, 5, 99, 0, 0,
		                    0, 0, 0},
		                   {"timer_delete", 226, 5, 99, 0, 0,
		                    0, 0, 0},
		                   {"clock_settime", 227, 5, 8, 3, 0,
		                    0, 0, 0},
		                   {"clock_gettime", 228, 5, 8, 4, 0,
		                    0, 0, 0},
		                   {"clock_getres", 229, 5, 8, 4, 0,
		                    0, 0, 0},
		                   {"clock_nanosleep", 230, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"exit_group", 231, 4142, 6, 0, 0,
		                    0, 0, 0},
		                   {"epoll_wait", 232, 5, 6, 4, 6,
		                    6, 0, 0},
		                   {"epoll_ctl", 233, 5, 6, 6, 6,
		                    4, 0, 0},
		                   {"tgkill", 234, 5, 6, 6, 6,
		                    0, 0, 0},
		                   {"utimes", 235, 5, 2, 142, 0,
		                    0, 0, 0},
		                   {"vserver", 236, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"mbind", 237, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"set_mempolicy", 238, 5, 6, 12, 12,
		                    0, 0, 0},
		                   {"get_mempolicy", 239, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"mq_open", 240, 5, 2, 6, 0,
		                    0, 0, 0},
		                   {"mq_unlink", 241, 5, 2, 0, 0,
		                    0, 0, 0},
		                   {"mq_timedsend", 242, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"mq_timedreceive", 243, 8, 0, 0, 0,
		                    0, 0, 0},
		                   {"mq_notify", 244, 5, 6, 3, 0,
		                    0, 0, 0},
		                   {"mq_getsetattr", 245, 5, 6, 4, 4,
		                    0, 0, 0},
		                   {"kexec_load", 246, 7, 12, 12, 4,
		                    12, 0, 0},
		                   {"waitid", 247, 5, 8, 8, 4,
		                    6, 0, 0},
		                   {"add_key", 248, 3, 0, 0, 0,
		                    0, 0, 0},
		                   {"request_key", 249, 3, 0, 0, 0,
		                    0, 0, 0},
		                   {"keyctl", 250, 7, 6, 5, 0,
		                    0, 0, 0},
		                   {"ioprio_set", 251, 5, 6, 6, 6,
		                    0, 0, 0},
		                   {"ioprio_get", 252, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"inotify_init", 253, 5, 4142, 0, 0,
		                    0, 0, 0},
		                   {"inotify_add_watch", 254, 5, 6, 2, 17,
		                    0, 0, 0},
		                   {"inotify_rm_watch", 255, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"migrate_pages", 256, 7, 0, 0, 0,
		                    0, 0, 0},
		                   {"openat", 257, 5, 6, 2, 6,
		                    0, 0, 0},
		                   {"mkdirat", 258, 5, 6, 2, 17,
		                    0, 0, 0},
		                   {"mknodat", 259, 5, 6, 2, 17,
		                    12, 0, 0},
		                   {"fchownat", 260, 5, 6, 2, 8,
		                    8, 6, 0},
		                   {"futimesat", 261, 5, 6, 2, 142,
		                    0, 0, 0},
		                   {"newfstatat", 262, 5, 6, 2, 4,
		                    6, 0, 0},
		                   {"unlinkat", 263, 5, 6, 2, 6,
		                    0, 0, 0},
		                   {"renameat", 264, 5, 6, 2, 6,
		                    2, 0, 0},
		                   {"linkat", 265, 5, 6, 2, 6,
		                    2, 6, 0},
		                   {"symlinkat", 266, 5, 2, 6, 2,
		                    0, 0, 0},
		                   {"readlinkat", 267, 5, 6, 2, 1,
		                    10, 0, 0},
		                   {"fchmodat", 268, 5, 6, 2, 17,
		                    6, 0, 0},
		                   {"faccessat", 269, 5, 6, 2, 6,
		                    6, 0, 0},
		                   {"pselect6", 270, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"ppoll", 271, 5, 4, 12, 3,
		                    3, 0, 0},
		                   {"unshare", 272, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"set_robust_list", 273, 7, 150, 10, 0,
		                    0, 0, 0},
		                   {"get_robust_list", 274, 7, 6, 150, 10,
		                    0, 0, 0},
		                   {"splice", 275, 8, 6, 4, 6,
		                    4, 10, 8},
		                   {"tee", 276, 8, 6, 6, 10,
		                    8, 0, 0},
		                   {"sync_file_range", 277, 5, 6, 10, 10,
		                    8, 0, 0},
		                   {"vmsplice", 278, 8, 6, 3, 12,
		                    8, 0, 0},
		                   {"move_pages", 279, 7, 6, 12, 4,
		                    3, 4, 6},
		                   {"utimensat", 280, 5, 6, 2, 143,
		                    6, 0, 0},
		                   {"epoll_pwait", 281, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"signalfd", 282, 5, 6, 3, 6,
		                    0, 0, 0},
		                   {"timerfd_create", 283, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"eventfd", 284, 5, 8, 6, 0,
		                    0, 0, 0},
		                   {"fallocate", 285, 5, 6, 6, 12,
		                    12, 0, 0},
		                   {"timerfd_settime", 286, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"timerfd_gettime", 287, 5, 6, 4, 0,
		                    0, 0, 0},
		                   {"accept4", 288, 5, 6, 4, 4,
		                    6, 0, 0},
		                   {"signalfd4", 289, 5, 6, 3, 6,
		                    0, 0, 0},
		                   {"eventfd2", 290, 5, 8, 6, 0,
		                    0, 0, 0},
		                   {"epoll_create1", 291, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"dup3", 292, 5, 6, 6, 6,
		                    0, 0, 0},
		                   {"pipe2", 293, 5, 14, 6, 0,
		                    0, 0, 0},
		                   {"inotify_init1", 294, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"preadv", 295, 8, 6, 3, 6,
		                    12, 0, 0},
		                   {"pwritev", 296, 8, 6, 3, 6,
		                    12, 0, 0},
		                   {"rt_tgsigqueueinfo", 297, 5, 8, 8, 6,
		                    4, 0, 0},
		                   {"perf_event_open", 298, 5, 0, 0, 0,
		                    0, 0, 0},
		                   {"recvmmsg", 299, 5, 6, 4, 8,
		                    8, 4, 0},
		                   {"fanotify_init", 300, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"fanotify_mark", 301, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"prlimit64", 302, 5, 8, 6, 3,
		                    4, 0, 0},
		                   {"name_to_handle_at", 303, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"open_by_handle_at", 304, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"clock_adjtime", 305, 5, 3, 4, 0,
		                    0, 0, 0},
		                   {"syncfs", 306, 5, 6, 0, 0,
		                    0, 0, 0},
		                   {"sendmmsg", 307, 5, 6, 4, 8,
		                    8, 0, 0},
		                   {"setns", 308, 5, 6, 6, 0,
		                    0, 0, 0},
		                   {"getcpu", 309, 5, 9, 9, 4,
		                    0, 0, 0},
		                   {"process_vm_readv", 310, 8, 0, 0, 0,
		                    0, 0, 0},
		                   {"process_vm_writev", 311, 8, 0, 0, 0,
		                    0, 0, 0},
		                   {"kcmp", 312, 5, 8, 8, 6,
		                    12, 12, 0},
		                   {"finit_module", 313, 5, 6, 2, 6,
		                    0, 0, 0},
		                   {"sched_setattr", 314, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"sched_getattr", 315, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"renameat2", 316, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"seccomp", 317, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"getrandom", 318, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"memfd_create", 319, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"kexec_file_load", 320, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"bpf", 321, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {"execveat", 322, 0, 0, 0, 0,
		                    0, 0, 0},
		                   {NULL, 4242, 0, 0, 0, 0, 0, 0, 0}};

#endif /* !LIST_SYSCALL_H_ */
