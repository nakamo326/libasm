	global	ft_strdup
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

	section	.text
ft_strdup:
	push	rdi			; stored ptr of src
	call	ft_strlen	; check len of src
	mov		rdi, rax	; mov len to arg of malloc
	call	malloc
	mov		rdi, rax	; mov ptr to dest
	pop		rsi			; restore ptr of src to rsi
	call	ft_strcpy
	ret