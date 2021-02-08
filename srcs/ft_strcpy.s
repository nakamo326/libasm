	global ft_strcpy

	section .text

ft_strcpy:
	mov rax, rdi

.loop:
	cmp byte [rsi], 0
	je .end
	mov rdi, [rsi]
	inc rdi
	inc rsi
	jmp .loop

.end:
	inc rdi
	mov rdi, 0
	ret