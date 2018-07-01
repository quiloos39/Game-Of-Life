#include<stdio.h>
#include<stdlib.h>
#define N 16 // Size of grid

int countNeighbors(int, int, int **);
int getState(int, int, int **);
void setState(int, int, int **, int);

int main()
{
	int **grid = (int **) malloc(sizeof(int *) * N); // initializing grid.
	int **tmp = (int **) malloc(sizeof(int *) * N);	// initializing grid for previous frames.
	int x;
	int y;
	for (y = 0; y < N; y++)
	{
		grid[y] = (int *) malloc(sizeof(int) * N);
		tmp[y] = (int *) malloc(sizeof(int) * N);
		for (x = 0; x < N; x++)
		{
			setState(x, y, grid, 0); // Sets initial states of all cells to 0 (dead) 
		}
	}
	
	setState(0, 2, grid, 1); //       *
	setState(1, 2, grid, 1); // ==>    *
	setState(2, 2, grid, 1); //      ***
	setState(2, 1, grid, 1); //
	setState(1, 0, grid, 1); //
	
	sleep(5);
	
	while (1)
	{
		system("cls");
		for (y = 0; y < N; y++)
		{
			for (x = 0; x < N; x++)
			{
				setState(x, y, tmp, getState(x, y, grid));
			}
		}
	
		for (y = 0; y < N; y++)
		{
			for (x = 0; x < N; x++)
			{
				int n = countNeighbors(x, y, tmp);
				if (getState(x, y, tmp))
				{
					if (n < 2 || n > 3) // if n (amount of neighbors) < 2 dies because under population. if n > 3 dies because of over population.
					{
						setState(x, y, grid, 0);
					}
					else
					{
						setState(x, y, grid, 1);
					}
				}
				else
				{
					if (n == 3)
					{
						setState(x, y, grid, 1);
					}
					else
					{
						setState(x, y, grid, 0);
					}
				}
				if (getState(x, y, grid))
				{
					printf("%c", '0');
				}
				else
				{
					printf("%c", ' ');
				}
			}
			printf("\n");
		}
		usleep(80000); // How fast game runs.
	}
	
	return 0;
}





int countNeighbors(int x, int y, int **grid) // Check for how many alive neighbors it has.
{
	int n = 0;
	if (getState(x + 1, y, grid))
	{
		n++;
	}
	
	if (getState(x - 1, y, grid))
	{
		n++;
	}
	
	if (getState(x, y + 1, grid))
	{
		n++;
	}
	if (getState(x, y - 1, grid))
	{
		n++;
	}
	
	if (getState(x + 1, y + 1, grid))
	{
		n++;
	}
	if (getState(x - 1, y + 1, grid))
	{
		n++;
	}
	if (getState(x + 1, y - 1, grid))
	{
		n++;
	}
	if (getState(x - 1, y - 1, grid))
	{
		n++;
	}
	return n;
}

int getState(int x, int y, int **grid)
{
	
	if (y >= 0 && x >= 0 && x < N && y < N) // Making sure that it's in bounds since our array is NxN in size.
	{
		return grid[y][x];
	}
	return 0;
}

void setState(int x, int y, int **grid, int state) // Sets cell state either 0 (dead) or 1 (alive).
{
	grid[y][x] = state;
}
