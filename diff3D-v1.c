#include <stdio.h>

//declaration of a function that returns a random integer
int randomChoice(int max);

main()
{
	int i,n,M,c,S;
	float av;
	int nmax=6;
	int seed;
	//setup of random number generator
	srandom(seed);
	av=0;
	//this for loop gives 100 different measurements
	for(seed=0;seed<1;seed++)
	{	c=0;
		int L[3]={1,1,1};
		M=0;
		S=10;
		//define an array to track if a site has been visited
		int check[3][10]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
		while(c<(3*S))
		{
			//if a site has now been visited for the first time the check[][] for that site changes to 1
			c=0;
			for(i=0;i<3;i++)
			{
				printf("%d\n",check[i][(L[i])-1]);
				if (check[i][(L[i])-1]<1)
				{
					check[i][(L[i]-1)]=1;
					//check if all sites have been reached
					for (n=0;n<S;n++)
					{
						if (check[i][n]>0)
						{
							c=c+1;
						}
					}
					printf("%d",c);
				}
			}
			//printf("{%d,%d,%d} - %d\n",L[0],L[1],L[2],c);
			//if randomChoice(nmax)=5 L[2] decreases
			if (randomChoice(nmax)==5)
			{
				L[2]=L[2]+1;
			}
			//if randomChoice(nmax)=4 L[2] decreases
			if (randomChoice(nmax)==4)
			{
				L[2]=L[2]-1;
			}
			//if randomChoice(nmax)=3 L[1] increases
			if (randomChoice(nmax)==3)
			{
				L[1]=L[1]+1;
			}
			//if randomChoice(nmax)=2 L[1] decreases
			if (randomChoice(nmax)==2)
			{
				L[1]=L[1]-1;
			}
			//if randomChoice(nmax)=1 L[0] increases
			if (randomChoice(nmax)==1)
			{
				L[1]=L[1]+1;
			}
			//if randomChoice(nmax)=0 L[0] decreases
			else
			{
				L[0]=L[0]-1;
			}
			//define periodic boundaies
			for(i=0;i<3;i++)
			{
				if (L[i]>S)
				{
					L[i]=1;
				}
				if (L[i]<1)
				{
					L[i]=S;
				}
			}
			M=M+1;
		}
		M=M-1;
		//calculation of the average number of jumps
		av=av+M;

	}
	av=(float)av/100;
	printf("Average number of jumps to visit all sites: %f\n",av);
}
	int randomChoice(int max)
	{
		return (random()%max);
	}
