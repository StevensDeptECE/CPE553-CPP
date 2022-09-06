	.file	"f.cc"
	.text
	.p2align 4,,15
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB0:
	.cfi_startproc
	imull	%edi, %edi
	movl	%edi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 8.3.0-6ubuntu1) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
