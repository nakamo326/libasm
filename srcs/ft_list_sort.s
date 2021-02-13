	global	ft_list_sort
	section	.text

;rdi ... **begin_list
;rsi ... int (*cmp)()

ft_list_sort:
	mov		r8, [rdi]		; *begin_list
	mov		rdx, rsi		; ptr to func

first_loop:
	cmp		r8, 0
	je		end
	mov		r11, [rdi + 8]

second_loop:
	cmp		r11, 0
	je		next_f_loop
	mov		rdi, [r8]
	mov		rsi, [r11]
	call	rdx
	cmp		rax, 0
	jl		exchange_data
	jmp		next_s_loop

exchange_data:
	mov		r10, [r8]
	mov		r8, [r11]
	mov		r11, [r10]

next_s_loop:
	mov		r11, [r11 + 8]	;set r9.next
	jmp		second_loop

next_f_loop:
	mov		r8, [r8 + 8]
	jmp		first_loop

end:
	ret