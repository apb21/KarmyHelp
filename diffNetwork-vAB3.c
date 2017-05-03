#include <stdio.h>
#include <stdlib.h>

#ifndef clusters
#define clusters 5
#endif

#ifndef nodes
#define nodes 4
#endif

#ifndef nmax
#define nmax (nodes+1)
#endif

//declaration of a function that returns a random integer
int randomChoice(int max){
	return (random()%max);
}

void main()
{
	int M,c,S;
	int X,Y;
	float av;
  int new1;
	int old0;
	int old1;
	int seed, seeds;
	int newChoice;
	av=0;
	//this for-loop gives "seeds" different measurements, increase "seeds" to increase the sample size.
	seeds = 1;
	for(seed=0;seed<seeds;seed++){
		srandom(seed);
		c=0;
		M=0;
		S=10;
		//define an array to keep track of the current position.
		int L[2]={1,1};
		old0 = L[0];
		old1 = L[1];
		//new1 is the suggested next node to move to
		new1 = 1;
		//define an array to track if a site has been visited
    int check[clusters][nodes];
		for (X = 0; X < clusters; X++) {
			for (Y = 0; Y < nodes; Y++) {
				check[X][Y] = 0;
			}
		}
		//while all nodes haven't been visited.
		while(c<(clusters*nodes)){
			//if a site has now been visited for the first time the check[X][Y] for that site changes to 1
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
			//repeat this until a different node from the current one is found
			while (new1 == old1) {
				//newChoice is between 0 and nodes+1
				newChoice = randomChoice(nmax+1);
				//If not on the last node
				if (old1<nodes) {
					//The max value for the next node is nodes.
					if (newChoice == nmax) {
						newChoice = nodes;
					}
				}
				if (old1>1){
					if (newChoice == 0) {
						newChoice = 1;
					}
				}
				new1 = newChoice;
			}
			if (new1 != old1) {
				switch (new1) {
					case 0:
						if (old0 == 1) {
							L[0] = clusters;
						} else {
							L[0] = old0-1;
						}
						L[1] = nodes;
						new1 = nodes;
						break;
					case nmax:
						if (L[0] == clusters) {
							L[0] = 1;
						} else {
							L[0] = old0+1;
						}
						L[1] = 1;
						new1 = 1;
						break;
					default:
						L[1] = new1;
						break;
				}
			}
      printf("{%d,%d} to {%d,%d}\n", old0, old1, L[0],L[1]);
			old0 = L[0];
			old1 = L[1];
			M=M+1;
		}
		M=M-1;
		//calculation of the average number of jumps
		av=av+M;
	}
	av=(float)av/seeds;
	printf("Average number of jumps to visit all %d sites: %f\n",clusters*nodes, av);
}
