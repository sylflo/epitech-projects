[BITS 64]

	global memset
	section .text
	
memset:
	push rbp		; prologue
	mov rbp, rsp
	xor rcx, rcx		; compteur
	
memset_loop:
	cmp rcx, rdx		; while rcx != rdx
	je memset_end
	mov [rdi+rcx], rsi	; remplissage
	inc rcx		; incrementation du compteur
	jmp memset_loop

memset_end:
	mov rax, rdi		; valeur de retour
	mov rsp,rbp		; epilogue
	pop rbp
	ret
