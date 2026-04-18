//�������(��Ͽ����������������)

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
	//����ͬ���ƶ�ָ��
	int j = p;
	int i = p - 1;
	//�������� pivot
	int mid = (q+p)/2;
	swap(&arr[q], &arr[mid]);
	int pivot = arr[q];
	//��ʼ�ƶ�
	for (; j < q; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[i + 1], &arr[q]);
	return i + 1;
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
	if (start >= end) return;
	if (end-start <= 15)
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
	printf("�������鳤��\n");
	if (scanf_s("%d", &n) != 1 || n < 0) return 0;
	if (n == 0) return 0;
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) return 0;
	for (int i = 0; i < n; i++)
	{
		if (scanf_s("%d", &arr[i]) != 1)
		{
			free(arr);
			return 0;
		}
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
