#include "stdio.h"
#include "time.h"

void Output_Array(int a[][5], int n, int m)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Input_Output_Array(int a[][5], int n, int m)
{
	int i, j;

	srand(time);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
		}
	}

	Output_Array(a, n, m);
}

void MinEl(int a[][5], int n, int m)
{
	int i, j;
	int min;
	int jmin = 0;
	min = a[0][0];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				jmin = j;
			}
		}
	}
	printf("min = %d jmin = %d", min, jmin);
	printf("\n");
	printf("\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][jmin] = 0;
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Delete(int a[][5], int n, int m)
{
	int i, j;
	int jmin;
	int b[10][10];

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
			{
				b[i][j] = a[i][j];
				printf("%d  ", b[i][j]);
			}
		}
		printf("\n");
	}
}

void main()
{
	int a[5][5];
	int n = 5, m = 5;
	
	Input_Output_Array(a, n, m);
	MinEl(a, n, m);
	Delete(a, n, m);
}