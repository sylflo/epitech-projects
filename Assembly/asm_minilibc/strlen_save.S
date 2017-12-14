[BITS 64]
	
	global strlen
	section .text
	
strlen:
	push rbp
	mov rbp, rsp
	mov rax, 0
	
strlen_loop:
	cmp BYTE[rdi+rax], 0
	je strlen_end
	inc rax
	jmp strlen_loop

strlen_end:
	mov rsp, rbp
	pop rbp
	ret
