#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

int end(){
  printf("Goodbye\n");
  exit(0);
}

int failure()
{
  printf("That was not a valid Integer. Program closing.\n");
  exit(0);
}

int CheckInt(char *X) {
  int IsInteger = TRUE;
  if (strlen(X)>10) {
    IsInteger = FALSE;
    return IsInteger;
  }
  for (int i = 0; i < strlen(X);i++)
  {
    if(X[i] < '0' || X[i] > '9')
    {
      IsInteger = FALSE;
      break;
    }
  }
  return IsInteger;
}

int GetInt(){
  char InputString[10];
  scanf("%s", InputString);
  if (CheckInt(InputString) == TRUE) {
    return atoi(InputString);
  } else {
    failure();
  }
}

void main()
{
  printf("This program will return the sum or product of all integers between two integers (inclusive).\n");
  int NUMB1,NUMB2,TOTAL;
  int LOOPING = 1;
  while (LOOPING == 1) {
    int LOOPED = 1;
    printf("Would you like sum (1), product (2) or stop (3)?\n");
    int FUNCTION;
    FUNCTION = GetInt();
    switch (FUNCTION) {
      case 3:{
        end();
      };
      case 1:{
        if (LOOPED == 1) {
          TOTAL = 0;
          printf("Input first integer.\n");
          NUMB1 = GetInt();
          printf("Input second integer.\n");
          NUMB2 = GetInt();
          if (NUMB1>NUMB2) {
            int SWAP;
            SWAP=NUMB1;
            NUMB1=NUMB2;
            NUMB2=SWAP;
          }
          do {
            TOTAL=TOTAL+NUMB1;
            NUMB1=NUMB1+1;
          } while (NUMB1<(NUMB2+1));
          printf("The sum is...\n");
          printf("%d\n",TOTAL);
          LOOPED = 0;
        }
      }
      case 2:{
        if (LOOPED == 1) {
          TOTAL=1;
          printf("Input first integer.\n");
          NUMB1 = GetInt();
          printf("Input second integer.\n");
          NUMB2 = GetInt();
          if (NUMB1>NUMB2)
          {
            int SWAP;
            SWAP=NUMB1;
            NUMB1=NUMB2;
            NUMB2=SWAP;
          }
          do {
            TOTAL=TOTAL*NUMB1;
            NUMB1=NUMB1+1;
          } while (NUMB1<(NUMB2+1));
          printf("The product is...\n");
          printf("%d\n",TOTAL);
          LOOPED = 0;
        }
      }
    }
  }
}
