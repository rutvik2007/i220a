	.file	"arith.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	sarl	$4, %eax
	movl	%edx, %ecx
	sall	$5, %ecx
	leal	(%ecx,%edx), %edx
	imull	%edx, %eax
	addl	8(%ebp), %eax
	popl	%ebp
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
