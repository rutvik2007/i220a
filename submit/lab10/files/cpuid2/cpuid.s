#Currently get_cpuid(int *eax, int *ebx, int *ecx, int *edx).
#Modify to get_cpuid(int cpuid_op, int *eax, int *ebx, int *ecx, int *edx).	
	.text
	.globl get_cpuid
get_cpuid:
	pushq   %r8
	pushq   %rcx
	movl 	%eax, %edi
	cpuid
	#largest param in %eax
	#12-char manufacturer string in ebx, edx, ecx.
	movl	%eax, (%rsi)	#store eax cpuid result
	movl	%ebx, (%rdx)	#store ebx cpuid result
	popq	%rax		#pop address for edxP
	movl    %edx, (%rcx)    #store edx cpuid result
	popq    %rax		#pop address for ecxP
	movl	%ecx, (%r8)	#store ecx cpuid result
	ret
	
