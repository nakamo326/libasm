	global	ft_atoi_base

	section	.text

ft_atoi_base:
	mov		rax, 1
	xor		rcx, rcx
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	jmp		check_space

remove_space:
	inc		rdi
check_space:
	cmp		rdi, 32
	je		remove_space
	jne		base_len

base_len:
	cmp		byte [rsi + rcx], 43
	je		end
	cmp		byte [rsi + rcx], 45
	je		end
	cmp		byte [rsi + rcx], 0
	je		is_valid_base
	inc		rcx
	jmp		base_len

next_loop:
	inc		r8
	cmp		r8, rcx
	mov		r8, 1 ; to store sign
	xor		r9, r9
	jmp		check_sign
is_valid_base:
	mov		r10b, byte [rsi + r8]
	mov		r9, r8
	add		r9, 1
inloop:
	cmp		r10b, byte [rsi + r9]
	je		end
	cmp		r9, rcx
	je		next_loop
	inc		r9
	jmp		inloop

negate_sign:
	mul		-1

inc_cntr:
	inc		r9

check_sign:
	cmp		byte [rdi + r9], 43 ;+
	je		inc_sign
	cmp		byte [rdi + r9], 45 ;-
	je		negate_sign
	ret




end:
	mov		rax, 0
	ret
