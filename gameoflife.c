#include<stdio.h>
#include<stdlib.h>
#define N 16

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
			setState(x, y, grid, 0);
		}
	}
	
	grid[0][0] = 1;
	grid[0][1] = 1;
	grid[0][2] = 1;
	grid[1][2] = 1;
	grid[2][1] = 1;
	
	sleep(1);
	
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
				if (getState(x, y, tmp) == 1)
				{
					if (n < 2 || n > 3)
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
				if (getState(x, y, grid) == 1)
				{
					printf("%c", '#');
				}
				else
				{
					printf("%c", ' ');
				}
			}
			printf("\n");
		}
		usleep(500000);
	}
	
	return 0;
}





int countNeighbors(int x, int y, int **grid)
{
	int n = 0;
	if (getState(x + 1, y, grid) == 1)
	{
		n++;
	}
	
	if (getState(x - 1, y, grid) == 1)
	{
		n++;
	}
	
	if (getState(x, y + 1, grid) == 1)
	{
		n++;
	}
	if (getState(x, y - 1, grid) == 1)
	{
		n++;
	}
	
	if (getState(x + 1, y + 1, grid) == 1)
	{
		n++;
	}
	if (getState(x - 1, y + 1, grid) == 1)
	{
		n++;
	}
	if (getState(x + 1, y - 1, grid) == 1)
	{
		n++;
	}
	if (getState(x - 1, y - 1, grid) == 1)
	{
		n++;
	}
	return n;
}

int getState(int x, int y, int **grid)
{
	
	if (y >= 0 && x >= 0 && x < N && y < N)
	{
		return grid[y][x];
	}
	return 0;
}

void setState(int x, int y, int **grid, int state)
{
	grid[y][x] = state;
}
