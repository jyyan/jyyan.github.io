#include <stdint.h>
#include <stdio.h>

uint32_t half_add(uint32_t a, uint32_t b) {
  if (b == 0) return a;
  uint32_t sum = a ^ b;             /* 相加但不進位 */
  uint32_t carry = (a & b) << 1;    /* 進位但不相加 */
  return half_add(sum, carry);
}

uint32_t multipliser32(uint32_t a, uint32_t b, uint32_t ab) {
  printf("a = %x, b = %x, ab = %x\n", a, b, ab);
  if (b == 0) {
    return ab;
  } else {
    return multipliser32(
        a,
        ~-b,
        half_add(ab,a)
        );
  }
}

void main(void) {
  uint32_t a = 14, b = 15, ab = 0;
  printf("multipliser32 :\n\t %d * %d = %d\n", a, b, multipliser32(a, b, ab));

}
