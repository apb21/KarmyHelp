#include <stdio.h>

#ifndef MIN
#define MIN 1
#endif

#ifndef MAX
#define MAX 20
#endif

void main() {
  int LAST,TOTAL, SWAP;
  LAST = MIN;
  TOTAL = MIN;
  printf("First %d numbers of the Fibonacci Sequence\n", MAX);
  printf(" 1 | %4d\n", LAST);
  printf(" 2 | %4d\n", TOTAL);
  for (int i = MIN; i < MAX-1; i++) {
    SWAP = TOTAL;
    TOTAL = TOTAL + LAST;
    LAST = SWAP;
    printf("%2d | ", i+2);
    printf("%4d\n", TOTAL);
  }
}
