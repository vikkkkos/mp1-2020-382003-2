#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"


void vvod_array(int a[], int n)
{
	int i;
	srand(time);

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
}

void vvod_array1(int a[], int n)
{
	int i;

	printf("������� ������ ��������� �� ����� �����\n");

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
}

void print_array(int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
}

void sort1(int a[], int n, int *nc, int *nsw)
{
	int i, tmp;
	int left, right;
	left = 0;
	right = n - 1;

	*nc = *nc + 1;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			*nc = *nc + 1;
			if (a[i] > a[i + 1])
			{
				tmp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = tmp;
				*nsw = *nsw + 1;
			}
		}
		right--;
		for (i = right; i > left; i--)
		{
			*nc = *nc + 1;
			if (a[i] < a[i - 1])
			{
				tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
				*nsw = *nsw + 1;
			}
		}
		left++;
	}
}

void sort2(int a[], int n, int *nc, int *nsw)
{
	int k, l;
	
	for (int i = 1; i < n; i++)
	{
		k = a[i];
		l = i - 1;
		
		*nc = *nc + 1;
		while (l >= 0 && a[l] > k)
		{
			a[l + 1] = a[l];
			l = l - 1;
			*nsw = *nsw + 1;
		}
		a[l + 1] = k;
	}
}

int a[10];
int b[11];

void merging(int left, int mid, int right, int *nc, int *nsw)
{
	int l1, l2, i;
	
	for (l1 = left, l2 = mid + 1, i = left; l1 <= mid && l2 <= right; i++)
	{
		*nc = *nc + 1;
		if (a[l1] <= a[l2])
		{
			b[i] = a[l1++];
			*nsw = *nsw + 1;
		}
		else
		{
			b[i] = a[l2++];
			*nsw = *nsw + 1;
		}
	}

	*nc = *nc + 1;
	while (l1 <= mid)
	{
		b[i++] = a[l1++];
		*nsw = *nsw + 1;
	}

	*nc = *nc + 1;
	while (l2 <= right)
	{
		b[i++] = a[l2++];
		*nsw = *nsw + 1;
	}

	
	for (i = left; i <= right; i++)
	{
		a[i] = b[i];
		*nsw = *nsw + 1;
	}
}

void sort3(int left, int right, int *nc, int *nsw)
{
	int mid;
	
	*nc = *nc + 1;
	if (left < right)
	{
		mid = (left + right) / 2;
		sort3(left, mid, nc, nsw);
		sort3(mid + 1, right, nc, nsw);
		merging(left, mid, right, nc, nsw);
	}
}

void linear_search(int a[], int n, int *nc)
{
	int k;
	int pos = -1;
	int i;

	printf("������� �����, ������� ���������� �����\n");
	scanf_s("%d", &k);

	for (i = 0; i < n; i++)
	{
		*nc = *nc + 1;
		if (a[i] == k)    
		{
			printf("������� %d ��������� �� %d �������\n", k, i + 1);
			break;
		}
	}
	*nc = *nc + 1;
	if (i == n)
		printf("������� %d �� ������ � �������\n", k);
}

void binary_search(int a[], int n, int *nc)
{
	int k;
	int left, right, mid;
	
	printf("������� �����, ������� ���������� �����\n");
	scanf_s("%d", &k);

	left = 0;
	right = n - 1;
	mid = (left + right) / 2;

	*nc = *nc + 1;
	while (left <= right)
	{
		*nc = *nc + 1;
		if (a[mid] < k)
		{
			left = mid + 1;
		}
		else
			*nc = *nc + 1;
			if (a[mid] == k) 
			{
				printf("������� %d ��������� �� %d �������.\n", k, mid + 1);
				break;
			}
			else
				right = mid - 1;
		mid = (left + right) / 2;
	}
	*nc = *nc + 1;
	if (left > right)
		printf("������� %d �� ������ � �������\n", k);
}

void menu()
{
	{
		printf("\n__________________________________________________\n");
		printf("\nMENU:\n");

		printf("\n�������� ������ ����� �������\n");
		printf("1. ������������� ����� ������ �������������\n");
		printf("2. ������ ������ �������\n");

		printf("\n3. ������� ������ �� �����\n");

		printf("\n�������� ������ ������ ���������\n");
		printf("4. �������� �����\n");
		printf("5. �������� ����� (������ ���� ������ ��� ������������)\n");

		printf("\n�������� ������ ���������� �������\n");
		printf("6. ��������� ����������\n");
		printf("7. ���������� ���������\n");
		printf("8. ���������� ��������\n");
		printf("0. ����� �� ���������\n");
		printf("\n__________________________________________________\n");
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	int a[10];
	int n = 10;
	int t = 10;
	LARGE_INTEGER start, finish, freq;
	double time;
	double timeAll[5];
	int nComp[5]; 
	int nSwaps[5];

	QueryPerformanceFrequency(&freq);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			vvod_array(a, n);
			break;
		}
		case 2:
		{
			vvod_array1(a, n);
			break;
		}
		case 3:
		{
			print_array(a, n);
			break;
		}
		case 4:
		{
			int nc = 0;
			QueryPerformanceCounter(&start);
			linear_search(a, n, &nc);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("comparisons %d\n", nc);
			break;
		}
		case 5:
		{
			int nc = 0;
			QueryPerformanceCounter(&start);
			binary_search(a, n, &nc);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("comparisons %d\n", nc);
			break;
		}
		case 6:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sort1(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			break;
		}
		case 7:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sort2(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			break;
		}
		case 8:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sort3(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			break;
		}
		}
	}
}
