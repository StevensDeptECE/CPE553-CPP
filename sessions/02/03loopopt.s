	.file	"03loopopt.cc"
	.text
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB1968:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4,,15
	.globl	_Z3sumyy
	.def	_Z3sumyy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3sumyy
_Z3sumyy:
.LFB1528:
	.seh_endprologue
	xorl	%eax, %eax
	cmpq	%rdx, %rcx
	ja	.L5
	.p2align 4,,10
.L4:
	addq	%rcx, %rax
	addq	$1, %rcx
	cmpq	%rcx, %rdx
	jnb	.L4
	rep ret
.L5:
	rep ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1529:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt4cout(%rip), %rcx
	movabsq	$4499999996500050000, %rdx
	call	_ZNSo9_M_insertIyEERSoT_
	leaq	47(%rsp), %rdx
	movl	$1, %r8d
	movq	%rax, %rcx
	movb	$10, 47(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I__Z3sumyy;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z3sumyy
_GLOBAL__sub_I__Z3sumyy:
.LFB1969:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z3sumyy
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (Rev2, Built by MSYS2 project) 6.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIyEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
