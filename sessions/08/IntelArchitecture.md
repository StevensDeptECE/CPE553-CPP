# Intel Architecture Summary

## Registers in an Intel CPU
Intel CPU has

PC = program counter (current instruction) rip  (instruction pointer)

16 integer 64-bit registers

ax,bx,cx,dx, si, di, bsp, sp 16 bits
80386
eax, ebx, ...  32-bits, low half is ax, bx, ...

80586???
rax, rbx, rcx, rdx, rsi, rdi, rbp, rsp ... r9, r10, r11, r12, r13, r14, r15

memory segments:
cs? ds?

floating point register

AVX: 16 128-bit vector registers   xmm0 to xmm15
AVX2: 16 256-bit                   ymm0 to ymm15
AVX512: 32 512-bit                 zmm0 to zmm31


hex
0x0     0000
0x1     0001
0x2     0010
0x3     0011
0x4     0100
0x5     0101
0x6     0110
0x7     0111
0x8     1000
0x9     1001
0xA     1010
0xB     1011
0xC     1100
0xD     1101
0xE     1110
0xF     1111

0xDEADBEEF = 1101 1110 1010 1101 1011 1110 1110 1111


rip - instruction pointer
rsp - stack pointer     - cannot be used
rbp - base pointer      - cannot be sued (can be used if you turn off debugging)