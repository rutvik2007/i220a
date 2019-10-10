	.file	"fact-while.c"
	.text
.globl fact
	.type	fact, @function
fact:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	$1, -8(%ebp)
	jmp	.L2
.L3:
	movl	-4(%ebp), %eax
	imull	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	addl	$1, -8(%ebp)
.L2:
	movl	-8(%ebp), %eax
	cmpl	8(%ebp), %eax
	jle	.L3
	movl	-4(%ebp), %eax
	leave
	ret
	.size	fact, .-fact
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
