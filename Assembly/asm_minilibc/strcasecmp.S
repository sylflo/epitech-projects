[BITS 64]
	
	global    strcasecmp
	section .text

strcasecmp:
	push rbp
	mov rbp, rsp
	mov rax, 0

strcasecmp_loop:
	xor rcx, rcx
	xor rdx, rdx
	
	mov cl, [rdi]
	mov dl, [rsi]

	cmp cl, 65
	jb check_case_dl
	cmp cl, 90
	ja check_case_dl
	add cl, 32
	
check_case_dl:	
	cmp dl, 65			
	jb end_check_case
	cmp dl, 90
	ja end_check_case
	add dl, 32

end_check_case:	
	cmp cl, 0
	jz strcasecmp_end
	cmp dl, 0
	jz strcasecmp_end
	cmp cl, dl
	jnz strcasecmp_end
	
	inc rdi
	inc rsi
	jmp strcasecmp_loop

strcasecmp_end:
	mov rax, rcx
	mov rbx, rdx
	mov rsp, rbp
	pop rbp
	sub rax, rbx
	ret


