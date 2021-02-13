	global	ft_list_size
	section	.text

;rdi ... *begin_list

ft_list_size:
	xor		rax, rax
	mov		rsi, rdi
loop:
	cmp		rdi , 0
	je		end
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		loop

end:
	mov		rdi,rsi
	ret
