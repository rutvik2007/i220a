	.file	"fact.c"
	.text
.globl rfact
	.type	rfact, @function
rfact:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %ebx
	movl	$1, %eax
	cmpl	$1, %ebx
	jle	.L2
	leal	-1(%ebx), %eax
	movl	%eax, (%esp)
	call	rfact
	imull	%ebx, %eax
.L2:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.size	rfact, .-rfact
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
