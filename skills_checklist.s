	.file	"skills_checklist.cc"
	.text
	.p2align 4
	.globl	_Z12optimize_inti
	.type	_Z12optimize_inti, @function
_Z12optimize_inti:
.LFB1590:
	.cfi_startproc
	endbr64
	leal	1(%rdi), %eax
	ret
	.cfi_endproc
.LFE1590:
	.size	_Z12optimize_inti, .-_Z12optimize_inti
	.p2align 4
	.globl	_Z14optimize_arrayv
	.type	_Z14optimize_arrayv, @function
_Z14optimize_arrayv:
.LFB1591:
	.cfi_startproc
	endbr64
	movl	$45, %eax
	ret
	.cfi_endproc
.LFE1591:
	.size	_Z14optimize_arrayv, .-_Z14optimize_arrayv
	.p2align 4
	.globl	_Z15optimize_array2v
	.type	_Z15optimize_array2v, @function
_Z15optimize_array2v:
.LFB1592:
	.cfi_startproc
	endbr64
	movl	$20, %eax
	ret
	.cfi_endproc
.LFE1592:
	.size	_Z15optimize_array2v, .-_Z15optimize_array2v
	.p2align 4
	.globl	_Z15optimize_array3v
	.type	_Z15optimize_array3v, @function
_Z15optimize_array3v:
.LFB1593:
	.cfi_startproc
	endbr64
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	movdqa	.LC0(%rip), %xmm0
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	movaps	%xmm0, (%rsp)
	movdqa	.LC1(%rip), %xmm0
	movl	8(%rsp), %eax
	movaps	%xmm0, 16(%rsp)
	addl	$13, %eax
	movq	40(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L8
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L8:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1593:
	.size	_Z15optimize_array3v, .-_Z15optimize_array3v
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.type	_GLOBAL__sub_I__Z12optimize_inti, @function
_GLOBAL__sub_I__Z12optimize_inti:
.LFB2074:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2074:
	.size	_GLOBAL__sub_I__Z12optimize_inti, .-_GLOBAL__sub_I__Z12optimize_inti
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z12optimize_inti
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC1:
	.long	4
	.long	5
	.long	6
	.long	7
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
