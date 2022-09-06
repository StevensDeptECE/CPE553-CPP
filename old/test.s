	ldr	r1, [r0]	@load location r0
	ldr	r1, [r0, #4]	@load location r0+4
	ldr	r1, [r0], #4	@location r0, then r0=r0+4
	ldr	r1, [r0, #4!]   @ first r0=r0+4, then load [r0]
