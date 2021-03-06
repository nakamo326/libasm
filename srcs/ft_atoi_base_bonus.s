	global	ft_atoi_base

	section	.text

ft_atoi_base:
	xor		rax, rax
	xor		rcx, rcx
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	xor		r11, r11
	jmp		check_space

remove_space:
	inc		rcx
check_space:
	cmp		byte [rdi + rcx], 9
	je		remove_space
	cmp		byte [rdi + rcx], 10
	je		remove_space
	cmp		byte [rdi + rcx], 11
	je		remove_space
	cmp		byte [rdi + rcx], 12
	je		remove_space
	cmp		byte [rdi + rcx], 13
	je		remove_space
	cmp		byte [rdi + rcx], 32
	je		remove_space
	add		rdi, rcx
	xor		rcx, rcx
	jne		base_len

base_len:
	cmp		byte [rsi + rcx], 43
	je		err_end
	cmp		byte [rsi + rcx], 45
	je		err_end
	cmp		byte [rsi + rcx], 9
	je		err_end
	cmp		byte [rsi + rcx], 10
	je		err_end
	cmp		byte [rsi + rcx], 11
	je		err_end
	cmp		byte [rsi + rcx], 12
	je		err_end
	cmp		byte [rsi + rcx], 13
	je		err_end
	cmp		byte [rsi + rcx], 32
	je		err_end
	cmp		byte [rsi + rcx], 0
	je		base_len_check
	inc		rcx
	jmp		base_len


base_len_check:
	cmp		rcx, 2
	jl		err_end
	jmp		is_valid_base
next_loop:
	inc		r8
	cmp		r8, rcx
	jne		is_valid_base
	xor		r9, r9
	jmp		check_sign
is_valid_base:

	mov		r10b, byte [rsi + r8]
	mov		r9, r8
	add		r9, 1
base_check_loop:
	cmp		r10b, byte [rsi + r9]
	je		err_end
	cmp		r9, rcx
	je		next_loop
	inc		r9
	jmp		base_check_loop

inc_minus:
	inc		r11

inc_counter:
	inc		r9

check_sign:
	cmp		byte [rdi + r9], 43 ;+
	je		inc_counter
	cmp		byte [rdi + r9], 45 ;-
	je		inc_minus
	and		r11, 0x1
	jz		set_plus
	mov		r11, 1
	add		rdi, r9
	jmp		calc_num

set_plus:
	mov		r11, 0
	add		rdi, r9
	jmp		calc_num

;r11 ... sign if num is minus 1,
;rcx ... base_len
;rdi ... src
;rsi ... base
calc_num:
	xor		r8, r8
	xor		r9, r9
	mov		r10, rcx		;base_len
	xor		rcx, rcx		;as a counter

loop_start:
	mov		r8b, byte [rdi + rcx]
	cmp		r8b, 0
	je		end
innerloop:
	cmp		r8b, byte [rsi + r9]
	jne		inc_innerloop
	mul		r10
	add		rax, r9
	inc		rcx
	xor		r9, r9
	jmp		loop_start

inc_innerloop:
	inc		r9
	cmp		r9, r10
	je		end
	jmp		innerloop

end:
	cmp		r11, 1
	je		negate_end
	ret

negate_end:
	neg		rax
	ret

err_end:
	ret
