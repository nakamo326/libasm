	global	ft_list_push_front
	extern	malloc
	section	.text

;rdi ... **begin_list
;rsi ... *data

ft_list_push_front:
	xor		r8, r8
	push	rdi
	push	rsi
	mov		rdi, 16	; sizeof(t_list)
	call	malloc WRT ..plt
	pop		rsi
	mov		[rax], rsi
	pop		rdi		; **begin_list
	mov		r8, [rdi]
	mov		[rax + 8], r8
	mov		[rdi], rax
	ret
