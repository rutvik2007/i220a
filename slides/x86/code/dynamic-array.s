	.file	"dynamic-array.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	8(%ebp), %eax
	leal	1(%eax,%eax), %edx
	leal	30(,%edx,4), %eax
	andl	$-16, %eax
	subl	%eax, %esp
	leal	23(%esp), %ebx
	andl	$-16, %ebx
	movl	%ebx, %ecx
	testl	%edx, %edx
	jle	.L2
	movl	$0, %eax
.L3:
	movl	%eax, (%ecx,%eax,4)
	addl	$1, %eax
	cmpl	%eax, %edx
	jg	.L3
.L2:
	movl	%edx, 4(%esp)
	movl	%ebx, (%esp)
	call	g
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L4
	call	__stack_chk_fail
.L4:
	movl	-4(%ebp), %ebx
	leave
	.p2align 4,,2
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
