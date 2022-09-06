

	.global _Z1fii

_Z1fii:
	add r0, r0, r1  @ r0 = r0 + r1
	bx 	lr      @ return to the caller

	.global _Z1gPi
_Z1fPi:
	mov	r2, #0
	mov	r3, #5
	.loop:
	ldr	r1, [r0]
	add	r2, r1    @r2 = r2 + r1
	add	r0, #4
	subs 	r3, #1
	bnz	.loop
	mov	r0, r2   @r0 now has the answer
	bx	lr       @return to caller
	
	


	
