	.file	"mul.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	20(%ebp), %ecx
	imull	%eax, %ecx
	movl	12(%ebp), %ebx
	imull	%edx, %ebx
	addl	%ebx, %ecx
	mull	%edx
	leal	(%ecx,%edx), %edx
	popl	%ebx
	popl	%ebp
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
