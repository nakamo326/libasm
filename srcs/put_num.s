	global	put_num
	section	.text

;rdi ... src
;rsi ... base
;rdx ... base_len
put_num:
	xor		r8,r8
	xor		r9,r9
	mov		r10, rdx
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
	neg		rax		;if sign_num is odd,negate rax
	ret