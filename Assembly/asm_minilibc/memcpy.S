[BITS 64]
	
	global memcpy
	section .text
	
memcpy:
	push rbp
	mov rbp, rsp
	xor rcx, rcx		;compteur
	
memcpy_loop:
	cmp rcx, rdx
	je memcpy_end
	mov bl, [rsi + rcx]
	mov [rdi + rcx], bl
	inc rcx
	jmp memcpy_loop
	
memcpy_end:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret
