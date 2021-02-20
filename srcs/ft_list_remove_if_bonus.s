	global	ft_list_remove_if
	extern	free
	section	.text

;(*cmp)(list_ptr->data, data_ref); if return 0,delete elm
;(*free_fct)(list_ptr->data); when delete elms,use this func to free mem

ft_list_remove_if:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 32
	mov		[rsp], rdi			;rdi ... **begin_list
	mov		[rsp + 8], rsi		;rsi ... *data_ref
	mov		[rsp + 16], rdx		;rdx ... int (*cmp)()
	mov		[rsp + 24], rcx		;rcx ... void (*free_fct)(void *))

nullcheck:
	cmp		rdi, 0
	je		end
	cmp		rdx, 0
	je		end
	cmp		rcx, 0
	je		end

start:
	mov		r9, [rsp]				;ptr from before elm
	mov		r8, [r9]			; (ptr to tlist)

cmp_first_elm:
	cmp		r8, 0
	je		end
	mov		rdi, [r8]			; ptr to data
	mov		rsi, [rsp + 8]		; data_ref
	call	[rsp + 16]
	cmp		rax, 0
	je		delete_first_elm
	jmp		to_next

delete_first_elm:
	mov		r11, r8		;store r8
	call	[rsp + 24]			; rdi is *data
	mov		r8, r11
	mov		r10, [r8 + 8]		; store ptr to next
	mov		rdi, r8
	call	free WRT ..plt		; free t_list
	mov		[r9], r10			; joint new next elm
	mov		[rsp], r9
	mov		r8, [r9]
	jmp		cmp_first_elm

to_next:
	mov		r9, r8
	mov		r8, [r8 + 8]

loop:
	cmp		r8, 0
	je		end
	mov		rdi, [r8]			; ptr to data
	mov		rsi, [rsp + 8]		; data_ref
	call	[rsp + 16]
	cmp		rax, 0
	je		delete_elm
	jmp		to_next

delete_elm:
	mov		r11, r8				;store r8
	call	[rsp + 24]			; rdi is *data
	mov		r8, r11
	mov		r10, [r8 + 8]		; store ptr to next
	mov		rdi, r8
	call	free WRT ..plt		; free t_list
	mov		[r9 + 8], r10		;set *next in prev elm
	mov		r8, r10
	jmp		loop

end:
	mov		rdi, [rsp]
	mov		rsp, rbp
	pop		rbp
	ret