	.file	"switch.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	$-1, %eax
	cmpl	$9, %edx
	ja	.L4
	jmp	*.L13(,%edx,4)
	.section	.rodata
	.align 4
	.align 4
.L13:
	.long	.L3
	.long	.L14
	.long	.L5
	.long	.L6
	.long	.L7
	.long	.L8
	.long	.L9
	.long	.L10
	.long	.L11
	.long	.L12
	.text
.L3:
	movl	$22, %eax
	jmp	.L4
.L5:
	movl	$45, %eax
	jmp	.L4
.L6:
	movl	$99, %eax
	jmp	.L4
.L7:
	movl	$77, %eax
	jmp	.L4
.L8:
	movl	$100, %eax
	jmp	.L4
.L9:
	movl	$87, %eax
	jmp	.L4
.L10:
	movl	$212, %eax
	jmp	.L4
.L11:
	movl	$23, %eax
	jmp	.L4
.L12:
	movl	$32, %eax
	jmp	.L4
.L14:
	movl	$33, %eax
.L4:
	popl	%ebp
	ret
	.size	f, .-f
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
