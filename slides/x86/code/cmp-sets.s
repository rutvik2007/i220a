	.file	"cmp-sets.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %edx
	testl	%edx, %edx
	sete	%cl
	movzbl	%cl, %ecx
	movl	12(%ebp), %eax
	cmpl	%eax, 8(%ebp)
	setl	%al
	movzbl	%al, %eax
	leal	(%ecx,%eax), %eax
	cmpl	20(%ebp), %edx
	setae	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	popl	%ebp
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
