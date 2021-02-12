	global	ft_strdup
	extern	__errno_location
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

	section	.text
ft_strdup:
	push	rdi			; stored ptr of src
	call	ft_strlen	; check len of src
	mov		rdi, rax	; mov len to arg of malloc
	call	malloc WRT ..plt
	cmp		rax, 0
	je		err
	mov		rdi, rax	; mov ptr to dest
	pop		rsi			; restore ptr of src to rsi
	call	ft_strcpy
	ret

err:
	mov		r8, 12
	call	__errno_location WRT ..plt
	mov		[rax], r8
	mov		rax, 0
	ret