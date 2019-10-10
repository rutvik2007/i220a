	.file	"swap.c"
	.text
.globl swap_add
	.type	swap_add, @function
swap_add:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	(%ebx), %eax
	movl	(%ecx), %edx
	movl	%edx, (%ebx)
	movl	%eax, (%ecx)
	leal	(%edx,%eax), %eax
	popl	%ebx
	popl	%ebp
	ret
	.size	swap_add, .-swap_add
.globl caller
	.type	caller, @function
caller:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$534, -4(%ebp)
	movl	$1057, -8(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	swap_add
	addl	-4(%ebp), %eax
	subl	-8(%ebp), %eax
	leave
	ret
	.size	caller, .-caller
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
