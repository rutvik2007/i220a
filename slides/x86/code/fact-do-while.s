	.file	"fact-do-while.c"
	.text
.globl fact
	.type	fact, @function
fact:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %ecx
	movl	$1, %edx
	movl	$1, %eax
.L2:
	imull	%edx, %eax
	addl	$1, %edx
	cmpl	%ecx, %edx
	jl	.L2
	popl	%ebp
	ret
	.size	fact, .-fact
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
