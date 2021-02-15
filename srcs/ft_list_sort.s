	global	ft_list_sort
	section	.text

;rdi ... **begin_list
;rsi ... int (*cmp)()

ft_list_sort:
	mov		rdi, [rdi]		; *begin_list
	mov		r8, rdi
	mov		rdx, rsi		; ptr to func

first_loop:
	cmp		r8, 0
	je		end
	mov		r9, [r8 + 8]

second_loop:
	cmp		r9, 0
	je		next_f_loop
	mov		rdi, [r8]
	mov		rsi, [r9]
	call	rdx
	cmp		rax, 0
	jg		swap_data
	jmp		next_s_loop

swap_data:
	mov		r10, [r8]
	mov		r11, [r9]
	mov		[r8], r11
	mov		[r9], r10

next_s_loop:
	mov		r9, [r9 + 8]	;set r9.next
	jmp		second_loop

next_f_loop:
	mov		r8, [r8 + 8]
	jmp		first_loop

end:
	ret