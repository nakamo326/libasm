	global ft_strcmp

	section .text

ft_strcmp:
	cmp		rdi, rsi
	je		eqend

loop:
	mov		byte al, [rdi]
	mov		byte bl, [rsi]
	cmp		al, bl
	jne		end

	inc		rdi
	inc		rsi
	jmp		loop

end:
	sub		al, bl
	movsx	rax, al
	ret

eqend:
	mov		rax, 0
	ret