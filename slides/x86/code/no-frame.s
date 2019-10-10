	.file	"no-frame.c"
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB13:
	.cfi_startproc
	movl	8(%esp), %eax
	addl	4(%esp), %eax
	addl	12(%esp), %eax
	ret
	.cfi_endproc
.LFE13:
	.size	sum, .-sum
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
