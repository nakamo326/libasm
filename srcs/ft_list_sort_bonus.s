	global	ft_list_sort
	section	.text

ft_list_sort:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	mov		[rsp], rdi		; rdi ... **begin_list
	mov		[rsp + 8], rsi	; rsi ... int (*cmp)()

	cmp		rdi, 0
	je		end
	cmp		rsi, 0
	je		end
	mov		r8, [rdi]		; *begin_list

first_loop:
	cmp		r8, 0
	je		end
	mov		r9, [r8 + 8]

second_loop:
	cmp		r9, 0
	je		next_f_loop
	mov		rdi, [r8]
	mov		rsi, [r9]
	call	[rsp + 8]
	cmp		rax, 0
	jg		swap_data
	jmp		next_s_loop

swap_data:
	mov		r10, [r8]
	mov		r11, [r9]
	mov		[r8], r11
	mov		[r9], r10
	jmp		second_loop

next_s_loop:
	mov		r9, [r9 + 8]	;set r9.next
	jmp		second_loop

next_f_loop:
	mov		r8, [r8 + 8]
	jmp		first_loop

end:
	mov		rdi, [rsp]
	mov		rsp, rbp
	pop		rbp
	ret