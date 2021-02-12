	global	ft_atoi_base

	section	.text

ft_atoi_base:
	xor		rcx, rcx
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	jmp		check_space

remove_space:
	inc		rcx
check_space:
	cmp		byte [rdi + rcx], 32 ;need to add space characters
	je		remove_space
	add		rdi, rcx
	xor		rcx, rcx
	jne		base_len

base_len:
	cmp		byte [rsi + rcx], 43
	je		err_end
	cmp		byte [rsi + rcx], 45
	je		err_end
	cmp		byte [rsi + rcx], 0
	je		is_valid_base
	inc		rcx
	jmp		base_len
;need to add base check

next_loop:
	inc		r8
	cmp		r8, rcx
	jne		is_valid_base
	xor		r8, r8 ; to store sign
	xor		r9, r9
	jmp		check_sign
is_valid_base:
	mov		r10b, byte [rsi + r8]
	mov		r9, r8
	add		r9, 1
inloop:
	cmp		r10b, byte [rsi + r9]
	je		err_end
	cmp		r9, rcx
	je		next_loop
	inc		r9
	jmp		inloop

inc_sign:
	inc		r8

inc_counter:
	inc		r9

check_sign:
	cmp		byte [rdi + r9], 43 ;+
	je		inc_counter
	cmp		byte [rdi + r9], 45 ;-
	je		inc_sign
	and		r8, 0x1
	jz		set_plus
	mov		r8, 1
	add		rdi, r9
	jmp		calc_num

set_plus:
	mov		r8, 0
	add		rdi, r9
	jmp		calc_num

;r8 ... sign if num is minus 1,
;rcx ... base_len
;rdi ... src
;rsi ... base
calc_num:
	push	r8 ; store sign
	xor		r8,r8
	xor		r9,r9
	mov		r10, rcx
	xor		rcx,rcx ;as a counter
	xor		rax,rax ;result

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
	jmp		innerloop

end:
	pop		r8
	cmp		r8, 1
	je		negate_end
	ret

negate_end:
	neg		rax
	ret

err_end:
	mov		rax, 0
	ret
