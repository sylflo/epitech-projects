[BITS 64]
	
	global memmove
	section .text
	
memmove:
	push rbp
	mov rbp, rsp
	xor rcx, rcx		;compteur
	
memmove_loop:
	cmp rcx, rdx
	je memmove_end
	mov bl, [rsi + rcx]
	mov [rdi + rcx], bl
	inc rcx
	jmp memmove_loop
	
memmove_end:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret
