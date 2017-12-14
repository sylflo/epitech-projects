[BITS 64]
	
	global strchr
	section .text
	
strchr:
	push rbp
	mov rbp, rsp
	mov rax, 0
	
loop_strchr:
	mov bl, [rdi]
	cmp bl, 0
	jz end_strchr
	cmp bl, sil
	jz end_strchr
	inc rdi
	jmp loop_strchr

end_strchr:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret


