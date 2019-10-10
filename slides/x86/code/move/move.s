	.file	"move.c"
	.text
.globl move
	.type	move, @function
move:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	movl	8(%ebp), %edx
	addw	(%edx), %ax
	movzwl	%ax, %eax
	popl	%ebp
	ret
	.size	move, .-move
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
