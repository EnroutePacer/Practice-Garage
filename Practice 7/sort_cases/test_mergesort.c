#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* temp, int left, int mid, int right)
{
int i = left;
int j = mid + 1;
int k = left;
while (i <= mid && j <= right)
{
if (arr[i] <= arr[j])
{
temp[k++] = arr[i++];
}
else
{
temp[k++] = arr[j++];
}
}
while (i <= mid)
{
temp[k++] = arr[i++];
}
while (j <= right)
{
temp[k++] = arr[j++];
}
for (int p = left; p <= right; p++)
{
arr[p] = temp[p];
}
}

void mergesort_core(int* arr, int* temp, int left, int right)
{
if (left >= right) return;
int mid = left + (right - left) / 2;
mergesort_core(arr, temp, left, mid);
mergesort_core(arr, temp, mid + 1, right);
if (arr[mid] <= arr[mid + 1]) return;
merge(arr, temp, left, mid, right);
}

void mergesort(int* arr, int n)
{
if (n <= 1) return;
int* temp = (int*)malloc(n * sizeof(int));
mergesort_core(arr, temp, 0, n - 1);
free(temp);
}

int main()
{
int n = 0;
printf("请输入数组长度\n");
scanf_s("%d", &n);
int* arr = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++)
{
scanf_s("%d", &arr[i]);
}
mergesort(arr, n);
printf("\n");
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
free(arr);
return 0;
}
