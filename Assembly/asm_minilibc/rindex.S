[BITS 64]
	
	global rindex
	section .text
	
rindex:
	push rbp
	mov rbp, rsp
	mov rax, 0
	
loop_rindex:
	mov bl, [rdi]
	cmp bl, 0
	jz end_rindex
	cmp bl, sil
	jz end_rindex
	inc rdi
	jmp loop_rindex

end_rindex:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret


