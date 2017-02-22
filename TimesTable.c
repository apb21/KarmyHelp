#include <stdio.h>

#ifndef MIN
#define MIN 1
#endif

#ifndef MAX
#define MAX 11
#endif

void main()
  {
    int x,y,z,n,t;
    printf(" ");
    for (t = 0; t < ((MAX-MIN)*4)-1; t++) {
      printf("_");
    }
    printf("\n");
    for(n=MIN; n<MAX; n++)
      {
        printf("|");
        for(x=MIN; x<MAX; x++)
          {
            y=n*x;
            printf("%3d|",y);
          }
        printf("\n|");
        for (z = MIN; z < MAX; z++) {
          printf("___|");
        }
        printf("\n");
      }
  }
