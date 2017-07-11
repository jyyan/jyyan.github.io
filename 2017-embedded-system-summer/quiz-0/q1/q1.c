#include <stdint.h>
#include <stdio.h>

uint32_t func32(uint32_t x) {
    uint32_t n = x;
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
    n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
    n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
    n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
    return n;
}
uint32_t func32for(uint32_t x) {
    uint32_t n = 0;
    for(int i=0; i<32; i++){
      if (x & 0x01) {
        n = (n << 1) | 0x01;
      } else {
        n = (n << 1);
      }
      x = x >> 1;
    }
    return n;
}

uint16_t func16(uint16_t x) {
    uint16_t n = x;
    n = ((n & 0xff00) >> 8) | ((n & 0x00ff) << 8);
    n = ((n & 0xf0f0) >>  4) | ((n & 0x0f0f) <<  4);
    n = ((n & 0xcccc) >>  2) | ((n & 0x3333) <<  2);
    n = ((n & 0xaaaa) >>  1) | ((n & 0x5555) <<  1);
    return n;
}

uint16_t func16for(uint16_t x) {
    uint16_t n = 0;
    for(int i=0; i<16; i++){
      if (x & 0x1) {
        n = (n << 1) | 0x01;
      } else {
        n = (n << 1);
      }
      x = x >> 1;
    }
    return n;
}

void main(){

  uint32_t s = 1001;
  printf("32bit\n\treq=\t%x\tres=\t %x\n", s, func32(s));
  printf("32bit-for\n\treq=\t%x\tres=\t %x\n", s, func32for(s));
  printf("16bit\n\treq=\t%x\tres=\t %x\n", s, func16(s));
  printf("16bit-for\n\treq=\t%x\tres=\t %x\n", s, func16for(s));
}
