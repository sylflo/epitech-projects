[BITS 64]
	
	global strlen
	section .text
	
strlen:
	push rbp
	mov rbp, rsp
	mov rax, 0
	
strlen_loop:
	mov bl, [rdi]
	cmp bl, 0
	jz strlen_end
	inc rdi
	inc rax
	jmp strlen_loop

strlen_end:
	mov rsp, rbp
	pop rbp
	ret
