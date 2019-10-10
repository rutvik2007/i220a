	.file	"multi-dim.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %eax
	imull	$1320, 12(%ebp), %edx
	addl	8(%ebp), %edx
	leal	(%eax,%eax,4), %eax
	addl	%eax, %eax
	addl	20(%ebp), %eax
	movl	(%edx,%eax,4), %eax
	popl	%ebp
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
