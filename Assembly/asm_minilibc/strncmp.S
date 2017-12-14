[BITS 64]
	
	global    strncmp
	section .text

strncmp:
	push rbp
	mov rbp, rsp
	mov rax, 0

strncmp_loop:
	xor rcx, rcx
	xor rdx, rdx
	
	mov bl, [rdi]
	mov cl, [rsi]
	
	cmp bl, 0
	jz strncmp_end
	
	cmp cl, 0
	jz strncmp_end
	
	inc rdi
	inc rsi
	jmp strncmp_loop

strncmp_end:
	mov rsp, rbp
	pop rbp
	mov rax, rdi
	ret
