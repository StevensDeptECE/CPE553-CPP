	.file	"thread1.cc"
	.text
	.p2align 4
	.globl	_Z7depositv
	.type	_Z7depositv, @function
_Z7depositv:
.LFB2811:
	.cfi_startproc
	endbr64
	addl	$1000000000, balance(%rip)
	ret
	.cfi_endproc
.LFE2811:
	.size	_Z7depositv, .-_Z7depositv
	.p2align 4
	.globl	_Z8withdrawv
	.type	_Z8withdrawv, @function
_Z8withdrawv:
.LFB2812:
	.cfi_startproc
	endbr64
	movl	balance(%rip), %edx
	movl	$1000000000, %eax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L5:
	testl	%edx, %edx
	jle	.L4
	subl	$1, %edx
	movl	$1, %ecx
.L4:
	subl	$1, %eax
	jne	.L5
	testb	%cl, %cl
	je	.L3
	movl	%edx, balance(%rip)
.L3:
	ret
	.cfi_endproc
.LFE2812:
	.size	_Z8withdrawv, .-_Z8withdrawv
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"balance="
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2813:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$8, %edx
	leaq	.LC0(%rip), %rsi
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	balance(%rip), %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	7(%rsp), %rsi
	movl	$1, %edx
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L14
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L14:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE2813:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_balance, @function
_GLOBAL__sub_I_balance:
.LFB3344:
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
.LFE3344:
	.size	_GLOBAL__sub_I_balance, .-_GLOBAL__sub_I_balance
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_balance
	.globl	balance
	.bss
	.align 4
	.type	balance, @object
	.size	balance, 4
balance:
	.zero	4
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
