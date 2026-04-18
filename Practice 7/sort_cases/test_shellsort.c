#include <stdio.h>
#include <stdlib.h>

void shellsort(int* arr, int n)
{
if (n <= 1) return;
int gap = 1;
while (gap < n / 3)
{
gap = gap * 3 + 1;
}
for (; gap >= 1; gap /= 3)
{
for (int i = gap; i < n; i++)
{
int temp = arr[i];
int j = i - gap;
while (j >= 0 && arr[j] > temp)
{
arr[j + gap] = arr[j];
j -= gap;
}
arr[j + gap] = temp;
}
}
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
shellsort(arr, n);
printf("\n");
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
free(arr);
return 0;
}
