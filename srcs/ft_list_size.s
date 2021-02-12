	global	ft_list_size
	section	.text

;rdi ... *begin_list

ft_list_size:
	xor		rax, rax
	xor		r8, r8
loop:
	mov		r8, [rdi + 8]
	cmp		r8 , 0
	je		end
	inc		rax
	jmp		loop

end:
	ret
