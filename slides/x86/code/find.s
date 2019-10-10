	.file	"array.c"
	.text
.globl find
	.type	find, @function
find:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	16(%ebp), %ebx
	movl	$-1, %eax
	testl	%edx, %edx
	jle	.L2
	movl	$0, %eax
	cmpl	%ebx, (%ecx)
	jne	.L4
	jmp	.L2
.L5:
	cmpl	%ebx, (%ecx,%eax,4)
	je	.L2
.L4:
	addl	$1, %eax
	cmpl	%eax, %edx
	.p2align 4,,3
	jg	.L5
	movl	$-1, %eax
.L2:
	popl	%ebx
	popl	%ebp
	ret
	.size	find, .-find
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
