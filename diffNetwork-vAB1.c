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
	int nmax;
  int new0, new1;
	int seed, seeds;
	int thisChoice;
  int moves[5][4] = {{4,4,3,3},{4,4,3,3},{4,4,3,3},{4,4,3,3},{4,4,3,3}};
  int routes[5][4][4][2] =
  {
    {
      {
        {1,2},
        {1,3},
        {1,4},
        {5,2}
      },
      {
        {1,1},
        {1,3},
        {1,4},
        {2,1}
      },
      {
        {1,1},
        {1,2},
        {1,4},
        {0,0}
      },
      {
        {1,1},
        {1,2},
        {1,3},
        {0,0}
      }
    },
    {
      {
        {2,2},
        {2,3},
        {2,4},
        {1,2}
      },
      {
        {2,1},
        {2,3},
        {2,4},
        {3,1}
      },
      {
        {2,1},
        {2,2},
        {2,4},
        {0,0}
      },
      {
        {2,1},
        {2,2},
        {2,3},
        {0,0}
      }
    },
    {
      {
        {3,2},
        {3,3},
        {3,4},
        {2,2}
      },
      {
        {3,1},
        {3,3},
        {3,4},
        {4,1}
      },
      {
        {3,1},
        {3,2},
        {3,4},
        {0,0}
      },
      {
        {3,1},
        {3,2},
        {3,3},
        {0,0}
      }
    },
    {
      {
        {4,2},
        {4,3},
        {4,4},
        {3,2}
      },
      {
        {4,1},
        {4,3},
        {4,4},
        {5,1}
      },
      {
        {4,1},
        {4,2},
        {4,4},
        {0,0}
      },
      {
        {4,1},
        {4,2},
        {4,3},
        {0,0}
      }
    },
    {
      {
        {5,2},
        {5,3},
        {5,4},
        {4,2}
      },
      {
        {5,1},
        {5,3},
        {5,4},
        {1,1}
      },
      {
        {5,1},
        {5,2},
        {5,4},
        {0,0}
      },
      {
        {5,1},
        {5,2},
        {5,3},
        {0,0}
      }
    }
  };
	av=0;
	//this for-loop gives "seeds" different measurements
	seeds = 100;
	for(seed=0;seed<seeds;seed++){
		srandom(seed);
		c=0;
		M=0;
		S=10;
		int L[2]={1,1};
		//define an array to track if a site has been visited
    int check[5][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
		while(c<(5*4)){
			//if a site has now been visited for the first time the check[X][Y][Z] for that site changes to 1
			c=0;
			if (check[L[0]-1][L[1]-1] == 0){
				check[L[0]-1][L[1]-1] = 1;
				//check if all sites have been reached
				for (X = 0; X < 5; X++) {
					for (Y = 0; Y < 4; Y++) {
						c = c + check[X][Y];
					}
				}
			}
      nmax = moves[L[0]-1][L[1]-1];
			thisChoice = randomChoice(nmax);
      new0 = routes[L[0]-1][L[1]-1][thisChoice][0];
      new1 = routes[L[0]-1][L[1]-1][thisChoice][1];
      //printf("{%d,%d} to {%d,%d}\n", L[0],L[1],new0,new1);
      L[0]=new0;
      L[1]=new1;
			M=M+1;
		}
		M=M-1;
		//calculation of the average number of jumps
		av=av+M;
	}
	av=(float)av/seeds;
	printf("Average number of jumps to visit all %d sites: %f\n",5*4, av);
}
