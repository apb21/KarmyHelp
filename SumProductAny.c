main()
{
printf("This program will return the sum or product of all integers between two integers (inclusive).\n");
int NUMB1,NUMB2,TOTAL,FUNCTION;
printf("Would you like sum (1), product (2) or stop (3)?\n");
scanf("%d",&FUNCTION);
if (FUNCTION==1) {
  TOTAL=0;
  printf("Input first integer.\n");
  scanf("%d",&NUMB1);
  printf("Input second integer.\n");
  scanf("%d",&NUMB2);
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
  main();
} else { if (FUNCTION==2) {
  TOTAL=1;
  printf("Input first integer.\n");
  scanf("%d",&NUMB1);
  printf("Input second integer.\n");
  scanf("%d",&NUMB2);
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
  { printf("The product is...\n");
  printf("%d\n",TOTAL);
  main();
  }
} else if (FUNCTION==3) {
  printf("Goodbye!\n");
  } else { printf("Please enter 'sum', 'product' or 'stop'\n");
  main();
}
}
}
