#include <stdint.h>
#include <stdio.h>

void main(void) {
  void* p;
  uint32_t* pp;
  uint32_t a = 0xe3;

  p = &a;
  pp = (uint32_t*) p;

  printf("p = %p, pp = %p\n", p, pp);
  printf("p = %p, *p = %x, a = %x, &a = %p\n",p , (uint32_t) *p, a, &a);

  /**p = (*p) & ~1;*/
  /*printf("p = %p, *p = %x, a = %x, &a = %p, ~1 = %x\n",*p , p, a, &a, ~1);*/

}
