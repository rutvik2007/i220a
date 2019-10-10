	.file	"conditional-move.c"
	.text
.globl abs_diff
	.type	abs_diff, @function
abs_diff:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %ebx
	subl	%ecx, %ebx
	movl	%ecx, %eax
	subl	%edx, %eax
	cmpl	%edx, %ecx
	cmovg	%ebx, %eax
	popl	%ebx
	popl	%ebp
	ret
	.size	abs_diff, .-abs_diff
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
