	.file	"rect-array.c"
	.text
.globl sum_perimeters
	.type	sum_perimeters, @function
sum_perimeters:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	movl	12(%ebp), %esi
	movl	$0, %eax
	testl	%esi, %esi
	jle	.L2
	movl	8(%ebp), %edx
	movl	$0, %ecx
.L3:
	movl	16(%edx), %ebx
	addl	12(%edx), %ebx
	leal	(%eax,%ebx,2), %eax
	addl	$1, %ecx
	addl	$20, %edx
	cmpl	%esi, %ecx
	jne	.L3
.L2:
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.size	sum_perimeters, .-sum_perimeters
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
