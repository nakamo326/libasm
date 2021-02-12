	global	ft_read
	extern	__errno_location

	section	.text
ft_read:
	xor		rax, rax
	syscall
	cmp		rax, 0
	jl		err
	ret
err:
	mov		r8, rax
	neg		r8
	call	__errno_location WRT ..plt
	mov		[rax], r8
	mov		rax, -1
	ret