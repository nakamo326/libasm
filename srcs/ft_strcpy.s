	global ft_strcpy

	section .text
ft_strcpy:
	xor rcx, rcx

loop:
	mov	r9b, byte [rsi + rcx]
	mov	byte [rdi + rcx], r9b
	cmp	r9b, 0
	je	end
	inc	rcx
	jmp	loop

end:
	mov	rax, rdi
	ret