	.file	"quadmath.cc"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1396:
	.cfi_startproc
	endbr64
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1396:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.text
	.p2align 4
	.type	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, @function
_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0:
.LFB2455:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	240(%rdi,%rax), %r12
	testq	%r12, %r12
	je	.L9
	cmpb	$0, 56(%r12)
	movq	%rdi, %rbp
	je	.L5
	movsbl	67(%r12), %esi
.L6:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rax, %rdi
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZNSo5flushEv@PLT
.L5:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L6
	movl	$10, %esi
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L6
.L9:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE2455:
	.size	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, .-_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%Qf"
	.text
	.p2align 4
	.globl	_ZlsRSog
	.type	_ZlsRSog, @function
_ZlsRSog:
.LFB1873:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	leaq	.LC0(%rip), %rdx
	movq	%rdi, %r12
	movl	$64, %esi
	subq	$80, %rsp
	.cfi_def_cfa_offset 96
	movq	%fs:40, %rax
	movq	%rax, 72(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdi
	movl	$1, %eax
	call	quadmath_snprintf@PLT
	movq	72(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L13
	addq	$80, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movq	%r12, %rax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1873:
	.size	_ZlsRSog, .-_ZlsRSog
	.globl	__multf3
	.p2align 4
	.globl	_Z1fg
	.type	_Z1fg, @function
_Z1fg:
.LFB1874:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movdqa	%xmm0, %xmm1
	call	__multf3@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1874:
	.size	_Z1fg, .-_Z1fg
	.globl	__addtf3
	.p2align 4
	.globl	_Z6unary3g
	.type	_Z6unary3g, @function
_Z6unary3g:
.LFB1882:
	.cfi_startproc
	endbr64
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movaps	%xmm0, 16(%rsp)
	call	cosq@PLT
	movdqa	16(%rsp), %xmm1
	movaps	%xmm0, (%rsp)
	movdqa	%xmm1, %xmm0
	call	sinq@PLT
	movdqa	(%rsp), %xmm2
	movdqa	%xmm0, %xmm1
	movdqa	%xmm2, %xmm0
	call	__addtf3@PLT
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1882:
	.size	_Z6unary3g, .-_Z6unary3g
	.p2align 4
	.globl	_Z6unary4g
	.type	_Z6unary4g, @function
_Z6unary4g:
.LFB1883:
	.cfi_startproc
	endbr64
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movaps	%xmm0, 16(%rsp)
	call	expq@PLT
	movdqa	16(%rsp), %xmm1
	movaps	%xmm0, (%rsp)
	movdqa	%xmm1, %xmm0
	call	logq@PLT
	movdqa	(%rsp), %xmm2
	movdqa	%xmm0, %xmm1
	movdqa	%xmm2, %xmm0
	call	__addtf3@PLT
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1883:
	.size	_Z6unary4g, .-_Z6unary4g
	.p2align 4
	.globl	_Z6unary5g
	.type	_Z6unary5g, @function
_Z6unary5g:
.LFB1884:
	.cfi_startproc
	endbr64
	jmp	fabsq@PLT
	.cfi_endproc
.LFE1884:
	.size	_Z6unary5g, .-_Z6unary5g
	.p2align 4
	.globl	_Z6unary6g
	.type	_Z6unary6g, @function
_Z6unary6g:
.LFB2449:
	.cfi_startproc
	endbr64
	jmp	fabsq@PLT
	.cfi_endproc
.LFE2449:
	.size	_Z6unary6g, .-_Z6unary6g
	.p2align 4
	.globl	_Z6unary3d
	.type	_Z6unary3d, @function
_Z6unary3d:
.LFB1886:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	leaq	8(%rsp), %rdi
	movq	%rsp, %rsi
	call	sincos@PLT
	movsd	8(%rsp), %xmm0
	addsd	(%rsp), %xmm0
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1886:
	.size	_Z6unary3d, .-_Z6unary3d
	.p2align 4
	.globl	_Z6unary4d
	.type	_Z6unary4d, @function
_Z6unary4d:
.LFB1887:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movsd	%xmm0, 8(%rsp)
	call	exp@PLT
	movsd	8(%rsp), %xmm1
	movsd	%xmm0, (%rsp)
	movapd	%xmm1, %xmm0
	call	log@PLT
	addsd	(%rsp), %xmm0
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1887:
	.size	_Z6unary4d, .-_Z6unary4d
	.p2align 4
	.globl	_Z6unary5d
	.type	_Z6unary5d, @function
_Z6unary5d:
.LFB1888:
	.cfi_startproc
	endbr64
	andpd	.LC1(%rip), %xmm0
	ret
	.cfi_endproc
.LFE1888:
	.size	_Z6unary5d, .-_Z6unary5d
	.section	.text._Z2f1IgET_S0_S0_,"axG",@progbits,_Z2f1IgET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f1IgET_S0_S0_
	.type	_Z2f1IgET_S0_S0_, @function
_Z2f1IgET_S0_S0_:
.LFB2136:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	__addtf3@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2136:
	.size	_Z2f1IgET_S0_S0_, .-_Z2f1IgET_S0_S0_
	.section	.text._Z2f1IdET_S0_S0_,"axG",@progbits,_Z2f1IdET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f1IdET_S0_S0_
	.type	_Z2f1IdET_S0_S0_, @function
_Z2f1IdET_S0_S0_:
.LFB2137:
	.cfi_startproc
	endbr64
	addsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2137:
	.size	_Z2f1IdET_S0_S0_, .-_Z2f1IdET_S0_S0_
	.section	.text._Z2f1IfET_S0_S0_,"axG",@progbits,_Z2f1IfET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f1IfET_S0_S0_
	.type	_Z2f1IfET_S0_S0_, @function
_Z2f1IfET_S0_S0_:
.LFB2138:
	.cfi_startproc
	endbr64
	addss	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2138:
	.size	_Z2f1IfET_S0_S0_, .-_Z2f1IfET_S0_S0_
	.section	.text._Z2f1IjET_S0_S0_,"axG",@progbits,_Z2f1IjET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f1IjET_S0_S0_
	.type	_Z2f1IjET_S0_S0_, @function
_Z2f1IjET_S0_S0_:
.LFB2139:
	.cfi_startproc
	endbr64
	leal	(%rdi,%rsi), %eax
	ret
	.cfi_endproc
.LFE2139:
	.size	_Z2f1IjET_S0_S0_, .-_Z2f1IjET_S0_S0_
	.section	.text._Z2f1ImET_S0_S0_,"axG",@progbits,_Z2f1ImET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f1ImET_S0_S0_
	.type	_Z2f1ImET_S0_S0_, @function
_Z2f1ImET_S0_S0_:
.LFB2140:
	.cfi_startproc
	endbr64
	leaq	(%rdi,%rsi), %rax
	ret
	.cfi_endproc
.LFE2140:
	.size	_Z2f1ImET_S0_S0_, .-_Z2f1ImET_S0_S0_
	.section	.text._Z2f1InET_S0_S0_,"axG",@progbits,_Z2f1InET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f1InET_S0_S0_
	.type	_Z2f1InET_S0_S0_, @function
_Z2f1InET_S0_S0_:
.LFB2141:
	.cfi_startproc
	endbr64
	movq	%rdi, %r9
	movq	%rdx, %rax
	movq	%rsi, %r8
	movq	%rcx, %rdx
	addq	%r9, %rax
	adcq	%r8, %rdx
	ret
	.cfi_endproc
.LFE2141:
	.size	_Z2f1InET_S0_S0_, .-_Z2f1InET_S0_S0_
	.globl	__subtf3
	.section	.text._Z2f2IgET_S0_S0_,"axG",@progbits,_Z2f2IgET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f2IgET_S0_S0_
	.type	_Z2f2IgET_S0_S0_, @function
_Z2f2IgET_S0_S0_:
.LFB2142:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	__subtf3@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2142:
	.size	_Z2f2IgET_S0_S0_, .-_Z2f2IgET_S0_S0_
	.section	.text._Z2f2IdET_S0_S0_,"axG",@progbits,_Z2f2IdET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f2IdET_S0_S0_
	.type	_Z2f2IdET_S0_S0_, @function
_Z2f2IdET_S0_S0_:
.LFB2143:
	.cfi_startproc
	endbr64
	subsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2143:
	.size	_Z2f2IdET_S0_S0_, .-_Z2f2IdET_S0_S0_
	.section	.text._Z2f2IfET_S0_S0_,"axG",@progbits,_Z2f2IfET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f2IfET_S0_S0_
	.type	_Z2f2IfET_S0_S0_, @function
_Z2f2IfET_S0_S0_:
.LFB2144:
	.cfi_startproc
	endbr64
	subss	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2144:
	.size	_Z2f2IfET_S0_S0_, .-_Z2f2IfET_S0_S0_
	.section	.text._Z2f2IjET_S0_S0_,"axG",@progbits,_Z2f2IjET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f2IjET_S0_S0_
	.type	_Z2f2IjET_S0_S0_, @function
_Z2f2IjET_S0_S0_:
.LFB2145:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	subl	%esi, %eax
	ret
	.cfi_endproc
.LFE2145:
	.size	_Z2f2IjET_S0_S0_, .-_Z2f2IjET_S0_S0_
	.section	.text._Z2f2ImET_S0_S0_,"axG",@progbits,_Z2f2ImET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f2ImET_S0_S0_
	.type	_Z2f2ImET_S0_S0_, @function
_Z2f2ImET_S0_S0_:
.LFB2146:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE2146:
	.size	_Z2f2ImET_S0_S0_, .-_Z2f2ImET_S0_S0_
	.section	.text._Z2f2InET_S0_S0_,"axG",@progbits,_Z2f2InET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f2InET_S0_S0_
	.type	_Z2f2InET_S0_S0_, @function
_Z2f2InET_S0_S0_:
.LFB2147:
	.cfi_startproc
	endbr64
	movq	%rdi, %r9
	movq	%rsi, %r8
	movq	%r8, %rdi
	movq	%r9, %rax
	movq	%rdx, %r8
	subq	%r8, %rax
	movq	%rdi, %rdx
	sbbq	%rcx, %rdx
	ret
	.cfi_endproc
.LFE2147:
	.size	_Z2f2InET_S0_S0_, .-_Z2f2InET_S0_S0_
	.section	.text._Z2f3IgET_S0_S0_,"axG",@progbits,_Z2f3IgET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f3IgET_S0_S0_
	.type	_Z2f3IgET_S0_S0_, @function
_Z2f3IgET_S0_S0_:
.LFB2148:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	__multf3@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2148:
	.size	_Z2f3IgET_S0_S0_, .-_Z2f3IgET_S0_S0_
	.section	.text._Z2f3IdET_S0_S0_,"axG",@progbits,_Z2f3IdET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f3IdET_S0_S0_
	.type	_Z2f3IdET_S0_S0_, @function
_Z2f3IdET_S0_S0_:
.LFB2149:
	.cfi_startproc
	endbr64
	mulsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2149:
	.size	_Z2f3IdET_S0_S0_, .-_Z2f3IdET_S0_S0_
	.section	.text._Z2f3IfET_S0_S0_,"axG",@progbits,_Z2f3IfET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f3IfET_S0_S0_
	.type	_Z2f3IfET_S0_S0_, @function
_Z2f3IfET_S0_S0_:
.LFB2150:
	.cfi_startproc
	endbr64
	mulss	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2150:
	.size	_Z2f3IfET_S0_S0_, .-_Z2f3IfET_S0_S0_
	.section	.text._Z2f3IjET_S0_S0_,"axG",@progbits,_Z2f3IjET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f3IjET_S0_S0_
	.type	_Z2f3IjET_S0_S0_, @function
_Z2f3IjET_S0_S0_:
.LFB2151:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE2151:
	.size	_Z2f3IjET_S0_S0_, .-_Z2f3IjET_S0_S0_
	.section	.text._Z2f3ImET_S0_S0_,"axG",@progbits,_Z2f3ImET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f3ImET_S0_S0_
	.type	_Z2f3ImET_S0_S0_, @function
_Z2f3ImET_S0_S0_:
.LFB2152:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	imulq	%rsi, %rax
	ret
	.cfi_endproc
.LFE2152:
	.size	_Z2f3ImET_S0_S0_, .-_Z2f3ImET_S0_S0_
	.section	.text._Z2f3InET_S0_S0_,"axG",@progbits,_Z2f3InET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f3InET_S0_S0_
	.type	_Z2f3InET_S0_S0_, @function
_Z2f3InET_S0_S0_:
.LFB2153:
	.cfi_startproc
	endbr64
	imulq	%rdx, %rsi
	movq	%rdi, %rax
	imulq	%rdi, %rcx
	mulq	%rdx
	addq	%rsi, %rcx
	addq	%rcx, %rdx
	ret
	.cfi_endproc
.LFE2153:
	.size	_Z2f3InET_S0_S0_, .-_Z2f3InET_S0_S0_
	.globl	__divtf3
	.section	.text._Z2f4IgET_S0_S0_,"axG",@progbits,_Z2f4IgET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f4IgET_S0_S0_
	.type	_Z2f4IgET_S0_S0_, @function
_Z2f4IgET_S0_S0_:
.LFB2154:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	__divtf3@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2154:
	.size	_Z2f4IgET_S0_S0_, .-_Z2f4IgET_S0_S0_
	.section	.text._Z2f4IdET_S0_S0_,"axG",@progbits,_Z2f4IdET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f4IdET_S0_S0_
	.type	_Z2f4IdET_S0_S0_, @function
_Z2f4IdET_S0_S0_:
.LFB2155:
	.cfi_startproc
	endbr64
	divsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2155:
	.size	_Z2f4IdET_S0_S0_, .-_Z2f4IdET_S0_S0_
	.section	.text._Z2f4IfET_S0_S0_,"axG",@progbits,_Z2f4IfET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f4IfET_S0_S0_
	.type	_Z2f4IfET_S0_S0_, @function
_Z2f4IfET_S0_S0_:
.LFB2156:
	.cfi_startproc
	endbr64
	divss	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE2156:
	.size	_Z2f4IfET_S0_S0_, .-_Z2f4IfET_S0_S0_
	.section	.text._Z2f4IjET_S0_S0_,"axG",@progbits,_Z2f4IjET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f4IjET_S0_S0_
	.type	_Z2f4IjET_S0_S0_, @function
_Z2f4IjET_S0_S0_:
.LFB2157:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	xorl	%edx, %edx
	divl	%esi
	ret
	.cfi_endproc
.LFE2157:
	.size	_Z2f4IjET_S0_S0_, .-_Z2f4IjET_S0_S0_
	.section	.text._Z2f4ImET_S0_S0_,"axG",@progbits,_Z2f4ImET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f4ImET_S0_S0_
	.type	_Z2f4ImET_S0_S0_, @function
_Z2f4ImET_S0_S0_:
.LFB2158:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	xorl	%edx, %edx
	divq	%rsi
	ret
	.cfi_endproc
.LFE2158:
	.size	_Z2f4ImET_S0_S0_, .-_Z2f4ImET_S0_S0_
	.globl	__divti3
	.section	.text._Z2f4InET_S0_S0_,"axG",@progbits,_Z2f4InET_S0_S0_,comdat
	.p2align 4
	.weak	_Z2f4InET_S0_S0_
	.type	_Z2f4InET_S0_S0_, @function
_Z2f4InET_S0_S0_:
.LFB2159:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	__divti3@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2159:
	.size	_Z2f4InET_S0_S0_, .-_Z2f4InET_S0_S0_
	.section	.text._Z6unary1IgET_S0_,"axG",@progbits,_Z6unary1IgET_S0_,comdat
	.p2align 4
	.weak	_Z6unary1IgET_S0_
	.type	_Z6unary1IgET_S0_, @function
_Z6unary1IgET_S0_:
.LFB2160:
	.cfi_startproc
	endbr64
	pxor	.LC2(%rip), %xmm0
	ret
	.cfi_endproc
.LFE2160:
	.size	_Z6unary1IgET_S0_, .-_Z6unary1IgET_S0_
	.section	.text._Z6unary1IdET_S0_,"axG",@progbits,_Z6unary1IdET_S0_,comdat
	.p2align 4
	.weak	_Z6unary1IdET_S0_
	.type	_Z6unary1IdET_S0_, @function
_Z6unary1IdET_S0_:
.LFB2161:
	.cfi_startproc
	endbr64
	xorpd	.LC3(%rip), %xmm0
	ret
	.cfi_endproc
.LFE2161:
	.size	_Z6unary1IdET_S0_, .-_Z6unary1IdET_S0_
	.section	.text._Z6unary1IfET_S0_,"axG",@progbits,_Z6unary1IfET_S0_,comdat
	.p2align 4
	.weak	_Z6unary1IfET_S0_
	.type	_Z6unary1IfET_S0_, @function
_Z6unary1IfET_S0_:
.LFB2162:
	.cfi_startproc
	endbr64
	xorps	.LC4(%rip), %xmm0
	ret
	.cfi_endproc
.LFE2162:
	.size	_Z6unary1IfET_S0_, .-_Z6unary1IfET_S0_
	.section	.text._Z6unary1IjET_S0_,"axG",@progbits,_Z6unary1IjET_S0_,comdat
	.p2align 4
	.weak	_Z6unary1IjET_S0_
	.type	_Z6unary1IjET_S0_, @function
_Z6unary1IjET_S0_:
.LFB2163:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	negl	%eax
	ret
	.cfi_endproc
.LFE2163:
	.size	_Z6unary1IjET_S0_, .-_Z6unary1IjET_S0_
	.section	.text._Z6unary1ImET_S0_,"axG",@progbits,_Z6unary1ImET_S0_,comdat
	.p2align 4
	.weak	_Z6unary1ImET_S0_
	.type	_Z6unary1ImET_S0_, @function
_Z6unary1ImET_S0_:
.LFB2164:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	negq	%rax
	ret
	.cfi_endproc
.LFE2164:
	.size	_Z6unary1ImET_S0_, .-_Z6unary1ImET_S0_
	.section	.text._Z6unary1InET_S0_,"axG",@progbits,_Z6unary1InET_S0_,comdat
	.p2align 4
	.weak	_Z6unary1InET_S0_
	.type	_Z6unary1InET_S0_, @function
_Z6unary1InET_S0_:
.LFB2165:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	movq	%rsi, %rdx
	negq	%rax
	adcq	$0, %rdx
	negq	%rdx
	ret
	.cfi_endproc
.LFE2165:
	.size	_Z6unary1InET_S0_, .-_Z6unary1InET_S0_
	.section	.text._Z6unary2IgET_S0_,"axG",@progbits,_Z6unary2IgET_S0_,comdat
	.p2align 4
	.weak	_Z6unary2IgET_S0_
	.type	_Z6unary2IgET_S0_, @function
_Z6unary2IgET_S0_:
.LFB2166:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE2166:
	.size	_Z6unary2IgET_S0_, .-_Z6unary2IgET_S0_
	.section	.text._Z6unary2IdET_S0_,"axG",@progbits,_Z6unary2IdET_S0_,comdat
	.p2align 4
	.weak	_Z6unary2IdET_S0_
	.type	_Z6unary2IdET_S0_, @function
_Z6unary2IdET_S0_:
.LFB2167:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE2167:
	.size	_Z6unary2IdET_S0_, .-_Z6unary2IdET_S0_
	.section	.text._Z6unary2IfET_S0_,"axG",@progbits,_Z6unary2IfET_S0_,comdat
	.p2align 4
	.weak	_Z6unary2IfET_S0_
	.type	_Z6unary2IfET_S0_, @function
_Z6unary2IfET_S0_:
.LFB2168:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE2168:
	.size	_Z6unary2IfET_S0_, .-_Z6unary2IfET_S0_
	.section	.text._Z6unary2IjET_S0_,"axG",@progbits,_Z6unary2IjET_S0_,comdat
	.p2align 4
	.weak	_Z6unary2IjET_S0_
	.type	_Z6unary2IjET_S0_, @function
_Z6unary2IjET_S0_:
.LFB2169:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	ret
	.cfi_endproc
.LFE2169:
	.size	_Z6unary2IjET_S0_, .-_Z6unary2IjET_S0_
	.section	.text._Z6unary2ImET_S0_,"axG",@progbits,_Z6unary2ImET_S0_,comdat
	.p2align 4
	.weak	_Z6unary2ImET_S0_
	.type	_Z6unary2ImET_S0_, @function
_Z6unary2ImET_S0_:
.LFB2170:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	ret
	.cfi_endproc
.LFE2170:
	.size	_Z6unary2ImET_S0_, .-_Z6unary2ImET_S0_
	.section	.text._Z6unary2InET_S0_,"axG",@progbits,_Z6unary2InET_S0_,comdat
	.p2align 4
	.weak	_Z6unary2InET_S0_
	.type	_Z6unary2InET_S0_, @function
_Z6unary2InET_S0_:
.LFB2171:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	movq	%rsi, %rdx
	ret
	.cfi_endproc
.LFE2171:
	.size	_Z6unary2InET_S0_, .-_Z6unary2InET_S0_
	.section	.rodata.str1.1
.LC8:
	.string	"single precision eps:"
.LC11:
	.string	"Double precision eps:"
.LC14:
	.string	"Quad precision eps:"
	.globl	__gttf2
	.globl	__eqtf2
.LC17:
	.string	"prod"
.LC18:
	.string	" "
.LC19:
	.string	"double"
.LC20:
	.string	": elapsed="
.LC22:
	.string	"__float128"
.LC23:
	.string	"__int128"
.LC24:
	.string	"uint64_t"
.LC25:
	.string	"uint32_t"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1892:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	leaq	_ZSt4cout(%rip), %rdi
	leaq	.LC8(%rip), %rsi
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	addq	$-128, %rsp
	.cfi_def_cfa_offset 160
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movss	.LC5(%rip), %xmm3
	pxor	%xmm5, %xmm5
	movss	.LC9(%rip), %xmm4
	movq	%rax, %rdi
	movaps	%xmm3, %xmm0
	jmp	.L69
	.p2align 4,,10
	.p2align 3
.L89:
	ucomiss	%xmm5, %xmm0
	setnp	%al
	cmovne	%edx, %eax
	testb	%al, %al
	jne	.L78
.L69:
	movaps	%xmm0, %xmm2
	mulss	%xmm4, %xmm0
	movaps	%xmm0, %xmm1
	addss	%xmm3, %xmm1
	comiss	%xmm0, %xmm1
	setbe	%dl
	ja	.L89
.L78:
	pxor	%xmm0, %xmm0
	leaq	47(%rsp), %rbp
	cvtss2sd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movq	%rax, %rdi
	movb	$10, 47(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rdi
	leaq	.LC11(%rip), %rsi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movsd	.LC6(%rip), %xmm2
	pxor	%xmm5, %xmm5
	movsd	.LC12(%rip), %xmm4
	movq	%rax, %rdi
	movapd	%xmm2, %xmm0
	jmp	.L71
	.p2align 4,,10
	.p2align 3
.L90:
	ucomisd	%xmm5, %xmm0
	setnp	%al
	cmovne	%edx, %eax
	testb	%al, %al
	jne	.L79
.L71:
	movapd	%xmm0, %xmm3
	mulsd	%xmm4, %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm2, %xmm1
	comisd	%xmm0, %xmm1
	setbe	%dl
	ja	.L90
.L79:
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movb	$10, 47(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.LC14(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movdqa	.LC7(%rip), %xmm2
	movq	%rax, %r12
.L73:
	movdqa	.LC15(%rip), %xmm1
	movdqa	%xmm2, %xmm0
	movaps	%xmm2, 16(%rsp)
	call	__multf3@PLT
	movdqa	.LC7(%rip), %xmm1
	movaps	%xmm0, (%rsp)
	call	__addtf3@PLT
	movdqa	(%rsp), %xmm2
	movdqa	%xmm2, %xmm1
	call	__gttf2@PLT
	testq	%rax, %rax
	jle	.L80
	movdqa	(%rsp), %xmm2
	pxor	%xmm1, %xmm1
	movdqa	%xmm2, %xmm0
	call	__eqtf2@PLT
	movdqa	(%rsp), %xmm2
	testq	%rax, %rax
	jne	.L73
.L80:
	movdqa	16(%rsp), %xmm0
	leaq	48(%rsp), %rdi
	movl	$64, %esi
	leaq	.LC0(%rip), %rdx
	movl	$1, %eax
	call	quadmath_snprintf@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movq	%r12, %rdi
	movb	$10, 47(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	call	clock@PLT
	movq	%rax, %rbx
	call	clock@PLT
	leaq	.LC17(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rbp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC18(%rip), %rsi
	subq	%rbx, %rbp
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC19(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbp, %xmm0
	mulsd	.LC21(%rip), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	call	clock@PLT
	movq	%rax, %rbx
	call	clock@PLT
	leaq	.LC17(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rbp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC18(%rip), %rsi
	subq	%rbx, %rbp
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC22(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbp, %xmm0
	mulsd	.LC21(%rip), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	call	clock@PLT
	movq	%rax, %rbx
	call	clock@PLT
	leaq	.LC17(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rbp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC18(%rip), %rsi
	subq	%rbx, %rbp
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC23(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbp, %xmm0
	mulsd	.LC21(%rip), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	call	clock@PLT
	movq	%rax, %rbx
	call	clock@PLT
	leaq	.LC17(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rbp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC24(%rip), %rsi
	subq	%rbx, %rbp
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbp, %xmm0
	mulsd	.LC21(%rip), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	call	clock@PLT
	movq	%rax, %rbx
	call	clock@PLT
	leaq	.LC17(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rbp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC18(%rip), %rsi
	subq	%rbx, %rbp
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC25(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbp, %xmm0
	mulsd	.LC21(%rip), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movq	120(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L91
	subq	$-128, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L91:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1892:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__ZlsRSog, @function
_GLOBAL__sub_I__ZlsRSog:
.LFB2445:
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
.LFE2445:
	.size	_GLOBAL__sub_I__ZlsRSog, .-_GLOBAL__sub_I__ZlsRSog
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZlsRSog
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC1:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 16
.LC2:
	.long	0
	.long	0
	.long	0
	.long	-2147483648
	.align 16
.LC3:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.align 16
.LC4:
	.long	-2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC5:
	.long	1065353216
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	0
	.long	1072693248
	.section	.rodata.cst16
	.align 16
.LC7:
	.long	0
	.long	0
	.long	0
	.long	1073676288
	.section	.rodata.cst4
	.align 4
.LC9:
	.long	1056964608
	.section	.rodata.cst8
	.align 8
.LC12:
	.long	0
	.long	1071644672
	.section	.rodata.cst16
	.align 16
.LC15:
	.long	0
	.long	0
	.long	0
	.long	1073610752
	.section	.rodata.cst8
	.align 8
.LC21:
	.long	-1598689907
	.long	1051772663
	.hidden	__dso_handle
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
