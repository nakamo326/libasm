	global ft_strcmp

	section .text
ft_strcmp:
	cmp		rdi, rsi
	je		eqend
	xor		rcx, rcx

loop:
	mov		al, byte [rdi + rcx]
	cmp		al, byte [rsi + rcx]
	jne		end
	cmp		al, 0
	je		end
	inc		rcx
	jmp		loop

end:
	sub		al, byte [rsi + rcx]
	movsx	rax, al
	ret

eqend:
	xor		rax, rax
	ret