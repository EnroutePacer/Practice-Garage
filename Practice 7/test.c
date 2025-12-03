//组合快速排序(组合插入排序)

#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int part(int* arr, int p, int q)
{
	//设置low和high两个指针
	int lo = p;
	int hi = q - 1;
	//设置中轴 pivot
	int mid = (q+p)/2;
	swap(&arr[q], &arr[mid]);
	int pivot = arr[q];
	//开始移动
	while (1)
	{
		while (arr[lo] <= pivot)
		{
			lo++;
		}
		while (hi >= p && arr[hi] >= pivot)
		{
			hi--;
		}
		if (lo >= hi) break;
		else
		{
			swap(&arr[lo], &arr[hi]);
			lo++;
			hi--;
		}
	}
	swap(&arr[lo], &arr[q]);
	return lo;
}
void insertionsort(int* arr, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= start && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
void quicksort(int* arr, int start, int end)
{
	if (end-start <= 50)
	{
		insertionsort(arr, start, end);
		return;
	}
	else
	{
		int par;
		par = part(arr, start, end);
		quicksort(arr, start, par - 1);
		quicksort(arr, par + 1, end);
	}
}
int main()
{
	int n = 0;
	printf("输入数组长度\n");
	scanf_s("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	quicksort(arr, 0, n - 1);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}