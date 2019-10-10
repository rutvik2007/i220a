	.file	"indirect-goto.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	jmp	*8(%ebp)
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
