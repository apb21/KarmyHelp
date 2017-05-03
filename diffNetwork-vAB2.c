#include <stdio.h>
#include <stdlib.h>

#ifndef ACWExitNode
#define ACWExitNode 1
#endif

#ifndef CWExitNode
#define CWExitNode 2
#endif

//declaration of a function that returns a random integer
int randomChoice(int max){
	return (random()%max);
}

void main()
{
	int i,n,M,c,S;
	int X,Y,Z;
	float av;
	int nmax;
  int new1;
	int old0,old1;
	int seed, seeds;
	int newChoice;
	int clusters = 5;
	int nodes = 4;
	av=0;
	//this for-loop gives "seeds" different measurements
	seeds = 1;
	for(seed=0;seed<seeds;seed++){
		srandom(seed);
		c=0;
		M=0;
		S=10;
		int L[2]={1,1};
		//define an array to track if a site has been visited
    int check[clusters][nodes];
		for (X = 0; X < clusters; X++) {
			for (Y = 0; Y < nodes; Y++) {
				check[X][Y] = 0;
			}
		}
		while(c<(clusters*nodes)){
			//if a site has now been visited for the first time the check[X][Y][Z] for that site changes to 1
			c=0;
			if (check[L[0]-1][L[1]-1] == 0){
				check[L[0]-1][L[1]-1] = 1;
				//check if all sites have been reached
				for (X = 0; X < clusters; X++) {
					for (Y = 0; Y < nodes; Y++) {
						c = c + check[X][Y];
					}
				}
			}
			new1 = randomChoice(nodes)+1;
			old0 = L[0];
			old1 = L[1];
			if (new1 == old1){
				switch (old1) {
					case ACWExitNode:
						if (L[0] == 1){
							L[0]=clusters;
						} else {
							L[0] = L[0]-1;
						}
						L[1] = CWExitNode;
						break;
					case CWExitNode:
						if (L[0] == clusters) {
							L[0] = 1;
						} else {
							L[0] = L[0]+1;
						}
						L[1] = ACWExitNode;
						break;
					default:
						newChoice = randomChoice(2);
						if (newChoice == 1) {
							L[1] = L[1]+1;
						} else {
							L[1] = L[1]-1;
						}
				}
			} else {
				L[1] = new1;
			}
			if (L[1]>nodes) {
				L[1] = 1;
			}
			if (L[1]<1) {
				L[1] = nodes;
			}
      printf("{%d,%d} to {%d,%d}\n", old0, old1, L[0],L[1]);
			M=M+1;
		}
		M=M-1;
		//calculation of the average number of jumps
		av=av+M;
	}
	av=(float)av/seeds;
	printf("Average number of jumps to visit all %d sites: %f\n",clusters*nodes, av);
}
