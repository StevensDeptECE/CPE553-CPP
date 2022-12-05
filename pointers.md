# Pointers

A pointer is a location in memory. You can think of a pointer as an
unsigned integer, although you cannot add two pointers. The semantics is analogous to dates: $Tuesday + Wednesday$ does not make sense.

On the other hand $Tuesday + 1 = Wednesday$
and $Thursday - Tuesday = 2$

It is the same with pointers

For the special case, char* old C has an implementation of strings where the last letter is the character whose code is zero. This is called ASCII NUL, not to be confused with the null pointer which is NULL in old C, 0 in old C++, and nullptr since C++11.

```cpp
const char s[] = "constant string"; // size=15 bytes including \0
char s2[20];
strcpy(s2, s); // old C string copy (unsafe)
strncpy(s2, s, 20); // old C string copy (safer), don't copy more than 20 bytes

uint8_t* p = new uint8_t[10]; // point to a block of 10 bytes
uint32_t* q = new uint32_t[100]; // point to 400 bytes
// q points to first element of block
// q + 1 points to second element of block
// q[1] is the same as *(q+1)

// the address of operator is &
// the dereference operator is *
// these two are inverses
int x = 5;
int *r = &x; // r points to address of x
*r = 6; // write to the value r is pointing to (x changes)
```
