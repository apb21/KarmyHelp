#include <stdio.h>
#include <stdlib.h>

//declaration of a function that returns a random integer
int randomChoice(int max){
	return (random()%max);
}

void main()
{
	int i,n,M,c,S;
	int X,Y,Z;
	float av;
	int nmax=6;
	int seed, seeds;
	int thisChoice;
	av=0;
	//this for loop gives "seeds" different measurements
	seeds = 100;
	for(seed=0;seed<seeds;seed++){
		srandom(seed);
		c=0;
		M=0;
		S=10;
		int L[3]={1,1,1};
		//define an array to track if a site has been visited
		int check [S][S][S];
		for (X = 0; X < S; X++) {
			for (Y = 0; Y < S; Y++) {
				for (Z = 0; Z < S; Z++) {
					check[X][Y][Z] = 0;
				}
			}
		}
		while(c<(S*S*S)){
			//if a site has now been visited for the first time the check[X][Y][Z] for that site changes to 1
			c=0;
			if (check[L[0]-1][L[1]-1][L[2]-1] == 0){
				check[L[0]-1][L[1]-1][L[2]-1] = 1;
				//check if all sites have been reached
				for (X = 0; X < S; X++) {
					for (Y = 0; Y < S; Y++) {
						for (Z = 0; Z < S; Z++) {
							c = c + check[X][Y][Z];
						}
					}
				}
			}
			thisChoice = randomChoice(nmax);
			switch (thisChoice) {
				case 5:{
					L[2]=L[2]+1;
					break;
				}
				case 4:{
					L[2]=L[2]-1;
					break;
				}
				case 3:{
					L[1]=L[1]+1;
					break;
				}
				case 2:{
					L[1]=L[1]-1;
					break;
				}
				case 1:{
					L[0]=L[0]+1;
					break;
				}
				case 0:{
					L[0]=L[0]-1;
					break;
				}
				default:{
					printf("error at {%d,%d,%d}\n", L[0],L[1],L[2]);
					exit(0);
				}
			}
			//define periodic boundaries
			for(i=0;i<3;i++){
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
	av=(float)av/seeds;
	printf("Average number of jumps to visit all %d sites: %f\n",S*S*S, av);
}
