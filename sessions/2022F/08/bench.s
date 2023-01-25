	.file	"bench.cc"
	.text
	.p2align 4
	.globl	_Z3f1aii
	.type	_Z3f1aii, @function
_Z3f1aii:
.LFB0:
	.cfi_startproc
	endbr64
	leal	(%rdi,%rsi), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3f1aii, .-_Z3f1aii
	.p2align 4
	.globl	_Z3f1bii
	.type	_Z3f1bii, @function
_Z3f1bii:
.LFB1:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	subl	%esi, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	_Z3f1bii, .-_Z3f1bii
	.p2align 4
	.globl	_Z3f1cii
	.type	_Z3f1cii, @function
_Z3f1cii:
.LFB2:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	_Z3f1cii, .-_Z3f1cii
	.p2align 4
	.globl	_Z3f1dii
	.type	_Z3f1dii, @function
_Z3f1dii:
.LFB3:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	cltd
	idivl	%esi
	ret
	.cfi_endproc
.LFE3:
	.size	_Z3f1dii, .-_Z3f1dii
	.p2align 4
	.globl	_Z3f2amm
	.type	_Z3f2amm, @function
_Z3f2amm:
.LFB4:
	.cfi_startproc
	endbr64
	leaq	(%rdi,%rsi), %rax
	ret
	.cfi_endproc
.LFE4:
	.size	_Z3f2amm, .-_Z3f2amm
	.p2align 4
	.globl	_Z3f2bmm
	.type	_Z3f2bmm, @function
_Z3f2bmm:
.LFB5:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE5:
	.size	_Z3f2bmm, .-_Z3f2bmm
	.p2align 4
	.globl	_Z3f2cmm
	.type	_Z3f2cmm, @function
_Z3f2cmm:
.LFB6:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	imulq	%rsi, %rax
	ret
	.cfi_endproc
.LFE6:
	.size	_Z3f2cmm, .-_Z3f2cmm
	.p2align 4
	.globl	_Z3f2dmm
	.type	_Z3f2dmm, @function
_Z3f2dmm:
.LFB7:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	xorl	%edx, %edx
	divq	%rsi
	ret
	.cfi_endproc
.LFE7:
	.size	_Z3f2dmm, .-_Z3f2dmm
	.p2align 4
	.globl	_Z3f3add
	.type	_Z3f3add, @function
_Z3f3add:
.LFB8:
	.cfi_startproc
	endbr64
	divsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE8:
	.size	_Z3f3add, .-_Z3f3add
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
