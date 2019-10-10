	.file	"rect.c"
	.text
.globl perimeter
	.type	perimeter, @function
perimeter:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	16(%edx), %eax
	addl	12(%edx), %eax
	addl	%eax, %eax
	popl	%ebp
	ret
	.size	perimeter, .-perimeter
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
