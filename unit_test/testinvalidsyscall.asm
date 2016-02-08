section .text
	global _start

_start:
	call _exit

_exit:
	mov rax, 4242
	syscall

	mov rax, 60
	syscall
