	global ft_test
	section .text

ft_test:
	and		rdi, 0x1
	jz		guusuu
	jmp		kisuu

guusuu:
	mov		rax, 0
	ret

kisuu:
	mov		rax,1
	ret