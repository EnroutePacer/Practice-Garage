#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}

void down_adjust(int* arr, int size, int idx)
{
while (1)
{
int left = idx * 2 + 1;
int right = idx * 2 + 2;
int max_idx = idx;
if (left < size && arr[left] > arr[max_idx])
{
max_idx = left;
}
if (right < size && arr[right] > arr[max_idx])
{
max_idx = right;
}
if (max_idx == idx)
{
break;
}
swap(&arr[idx], &arr[max_idx]);
idx = max_idx;
}
}

void heapsort(int* arr, int n)
{
if (n <= 1) return;
for (int i = n / 2 - 1; i >= 0; i--)
{
down_adjust(arr, n, i);
}
for (int i = n - 1; i > 0; i--)
{
swap(&arr[0], &arr[i]);
down_adjust(arr, i, 0);
}
}

int main()
{
int n = 0;
printf("请输入数组长度\n");
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
heapsort(arr, n);
printf("\n");
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
free(arr);
return 0;
}
