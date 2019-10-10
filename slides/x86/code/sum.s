	.file	"sum.c"
	.text
.globl sum
	.type	sum, @function
sum:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	$0, %eax
	testl	%ecx, %ecx
	jle	.L2
	movl	$0, %edx
.L3:
	addl	(%ebx,%edx,4), %eax
	addl	$1, %edx
	cmpl	%ecx, %edx
	jne	.L3
.L2:
	popl	%ebx
	popl	%ebp
	ret
	.size	sum, .-sum
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
