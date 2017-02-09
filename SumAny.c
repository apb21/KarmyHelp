#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

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

int main()
{
  printf("This program will return the sum of all integers between two integers (inclusively) as a float.\n");
  printf("N.B. The maximum length of an integer is 10 digits.\n");
  int Int1, Int2;
  printf("Input first integer.\n");
  Int1 = GetInt();
  printf("Input second integer.\n");
  Int2 = GetInt()+1;
  if (Int1>Int2) {
    int Swap;
    Swap = Int1;
    Int1 = Int2;
    Int2 = Swap;
  }
  float Total = 0;
  for (int i = Int1; i < Int2; i++) {
    Total = Total + i;
  }
  printf("%f\n", Total);
}
