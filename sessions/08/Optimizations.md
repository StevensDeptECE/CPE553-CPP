# Optimizations
- constant expressions
  - regroup yourself
- automatic peephole optimization
  - reduce cost of * power of 2 to shift
  - reduce cost of / power of 2 to shift
  - x % 32 --> x & 31
- floating point: manual rewriting
   - manually collect constants
   - manually cancel algebraically
   - Horner's form
- inlining
- memory
>    - sequential memory access
>    - cache memory size
>    - paging
>    - preallocating space