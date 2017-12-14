[BITS 64]
	
	global    strcmp
	section .text

strcmp:
	push rbp
	mov rbp, rsp

strcmp_loop:	
	xor rdx, rdx
	xor rcx, rcx
	mov cl, [rdi]
	mov dl, [rsi]	
	cmp dl, 0
	jz strcmp_end
	cmp cl, 0
	jz strcmp_end
	cmp cl, dl
	jnz strcmp_end
	inc rdi
	inc rsi
	jmp strcmp_loop

strcmp_end:
	mov rax, rcx
	mov rbx, rdx
	sub rax, rbx
	mov rsp, rbp
	pop rbp
	ret
