	.file	"simple.c"
	.intel_syntax noprefix
	.text
.globl simple
	.type	simple, @function
simple:
	push	ebp
	mov	ebp, esp
	mov	edx, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [ebp+12]
	add	eax, DWORD PTR [edx]
	mov	DWORD PTR [edx], eax
	pop	ebp
	ret
	.size	simple, .-simple
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
