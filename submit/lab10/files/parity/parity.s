	.text
	.globl get_parity
#edi contains n	
get_parity:

	#@TODO: add code here to set eax to 1 iff edi has even parity
	
	testl %edi, -1
	jpe
	movl 1, %eax
	
	END:
	ret
	
