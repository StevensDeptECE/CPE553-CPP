	.file	"fraction.cc"
	.text
	.align 2
	.p2align 4
	.globl	_ZN8fractionC2Eii
	.type	_ZN8fractionC2Eii, @function
_ZN8fractionC2Eii:
.LFB1591:
	.cfi_startproc
	endbr64
	movl	%esi, (%rdi)
	movl	%edx, 4(%rdi)
	ret
	.cfi_endproc
.LFE1591:
	.size	_ZN8fractionC2Eii, .-_ZN8fractionC2Eii
	.globl	_ZN8fractionC1Eii
	.set	_ZN8fractionC1Eii,_ZN8fractionC2Eii
	.align 2
	.p2align 4
	.globl	_ZNK8fractionplERKS_
	.type	_ZNK8fractionplERKS_, @function
_ZNK8fractionplERKS_:
.LFB1593:
	.cfi_startproc
	endbr64
	movl	4(%rsi), %edx
	movl	(%rdi), %ecx
	movl	4(%rdi), %eax
	imull	%edx, %ecx
	movl	%ecx, %edi
	movl	(%rsi), %ecx
	imull	%eax, %ecx
	imull	%edx, %eax
	leal	(%rdi,%rcx), %edx
	salq	$32, %rax
	orq	%rdx, %rax
	ret
	.cfi_endproc
.LFE1593:
	.size	_ZNK8fractionplERKS_, .-_ZNK8fractionplERKS_
	.align 2
	.p2align 4
	.globl	_ZNK8fractionngEv
	.type	_ZNK8fractionngEv, @function
_ZNK8fractionngEv:
.LFB1594:
	.cfi_startproc
	endbr64
	movl	(%rdi), %edx
	movl	4(%rdi), %eax
	negl	%edx
	salq	$32, %rax
	movq	%rax, %rcx
	movl	%edx, %eax
	orq	%rcx, %rax
	ret
	.cfi_endproc
.LFE1594:
	.size	_ZNK8fractionngEv, .-_ZNK8fractionngEv
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"/"
	.text
	.p2align 4
	.globl	_ZlsRSoRK8fraction
	.type	_ZlsRSoRK8fraction, @function
_ZlsRSoRK8fraction:
.LFB1595:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rsi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	(%rsi), %esi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movl	$1, %edx
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	4(%rbx), %esi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movq	%rbp, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	_ZNSolsEi@PLT
	.cfi_endproc
.LFE1595:
	.size	_ZlsRSoRK8fraction, .-_ZlsRSoRK8fraction
	.align 2
	.p2align 4
	.globl	_ZNK8fraction6getNumEv
	.type	_ZNK8fraction6getNumEv, @function
_ZNK8fraction6getNumEv:
.LFB1596:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	ret
	.cfi_endproc
.LFE1596:
	.size	_ZNK8fraction6getNumEv, .-_ZNK8fraction6getNumEv
	.align 2
	.p2align 4
	.globl	_ZNK8fraction6getDenEv
	.type	_ZNK8fraction6getDenEv, @function
_ZNK8fraction6getDenEv:
.LFB1597:
	.cfi_startproc
	endbr64
	movl	4(%rdi), %eax
	ret
	.cfi_endproc
.LFE1597:
	.size	_ZNK8fraction6getDenEv, .-_ZNK8fraction6getDenEv
	.align 2
	.p2align 4
	.globl	_ZN8fraction6setNumEi
	.type	_ZN8fraction6setNumEi, @function
_ZN8fraction6setNumEi:
.LFB1598:
	.cfi_startproc
	endbr64
	movl	%esi, (%rdi)
	ret
	.cfi_endproc
.LFE1598:
	.size	_ZN8fraction6setNumEi, .-_ZN8fraction6setNumEi
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.type	_GLOBAL__sub_I__ZN8fractionC2Eii, @function
_GLOBAL__sub_I__ZN8fractionC2Eii:
.LFB2082:
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
.LFE2082:
	.size	_GLOBAL__sub_I__ZN8fractionC2Eii, .-_GLOBAL__sub_I__ZN8fractionC2Eii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN8fractionC2Eii
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
