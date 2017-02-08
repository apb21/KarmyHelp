#include<stdio.h>
int main()
{
  printf("This program will return the sum of all integers between two integers (inclusive).\n");
  int NUMB1, NUMB2;
  printf("Input first integer.\n");
  scanf("%d", &NUMB1);
  printf("Input second integer.\n");
  scanf("%d", &NUMB2);
  if (NUMB1>NUMB2) {
    int SWAP;
    SWAP = NUMB1;
    NUMB1 = NUMB2;
    NUMB2 = SWAP;
  }
  int TOTAL = 0;
  do{
    TOTAL = TOTAL + NUMB1;
    NUMB1 = NUMB1 + 1;
  } while(NUMB1 < (NUMB2 + 1));
  printf("%d\n", TOTAL);
}
