	.file	"main.cc"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1590:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	$2, %edx
	movl	$1, %esi
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	subq	$48, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leaq	16(%rsp), %rbp
	leaq	24(%rsp), %r12
	movq	%rbp, %rdi
	leaq	15(%rsp), %r13
	call	_ZN8fractionC1Eii@PLT
	movl	$3, %edx
	movl	$1, %esi
	movq	%r12, %rdi
	call	_ZN8fractionC1Eii@PLT
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	_ZNK8fractionplERKS_@PLT
	movq	%rbp, %rdi
	call	_ZNK8fractionngEv@PLT
	leaq	32(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, 32(%rsp)
	call	_ZlsRSoRK8fraction@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movb	$10, 15(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %rdi
	call	_ZNK8fraction6getNumEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	movl	%eax, %esi
	call	_ZNSolsEi@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movb	$10, 15(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %rdi
	call	_ZNK8fraction6getDenEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	movl	%eax, %esi
	call	_ZNSolsEi@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movb	$10, 15(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	$13, %esi
	movq	%r12, %rdi
	call	_ZN8fraction6setNumEi@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L5
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1590:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2072:
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
.LFE2072:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
