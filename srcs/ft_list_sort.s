	global	ft_list_sort
	section	.text

;rdi ... **begin_list
;rsi ... int (*cmp)()

ft_list_sort:
	;test
	mov		rdi, [rdi]		; *begin_list
	mov		r8, rdi
	;;;;;;;;;;;;;;;;;;;;;;;;
	mov		r9, [r8]		;*data
	mov		r11, [r8 + 8]
	mov		r9,	[r11]
	;;;;;;;;;;;;;;;;;;;;;;;;;
	mov		rdx, rsi		; ptr to func
	push	rsi

first_loop:
	mov		r9, r8
	cmp		r9, 0
	jz		end
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
	mov		[r8], r11
	mov		[r11], r10

next_s_loop:
	mov		r11, [r11 + 8]	;set r9.next
	jmp		second_loop

next_f_loop:
	mov		r8, [r8 + 8]
	jmp		first_loop

end:
	ret