	global	ft_list_push_front
	extern	malloc
	section	.text

;rdi ... **begin_list
;rsi ... *data

ft_list_push_front:
	cmp		rdi, 0
	je		err_end
	push	rdi
	push	rsi
	mov		rdi, 16				; sizeof(t_list)
	call	malloc WRT ..plt
	pop		rsi					; *data
	mov		[rax], rsi			; rax is *t_list
	pop		rdi					; **begin_list
	mov		r8, [rdi]			; ptr to tlist
	mov		[rax + 8], r8		; set new_elm->next
	mov		[rdi], rax
	ret

err_end:
	ret