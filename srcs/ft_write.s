	global ft_write
	extern __errno_location

	section .text

ft_write:
	mov		rax, 1
	syscall
	cmp		rax, 0
	jl		err
	ret

err:
	mov		r8, rax
	call	__errno_location
	mov		[rax], r8
	mov		rax, -1