#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void radixsort(int* arr, int n)
{
if (n <= 1) return;
uint32_t* data = (uint32_t*)malloc(n * sizeof(uint32_t));
uint32_t* temp = (uint32_t*)malloc(n * sizeof(uint32_t));
if (data == NULL || temp == NULL)
{
free(data);
free(temp);
return;
}
for (int i = 0; i < n; i++)
{
data[i] = (uint32_t)arr[i] ^ 0x80000000u;
}
for (int shift = 0; shift < 32; shift += 8)
{
int cnt[256] = { 0 };
for (int i = 0; i < n; i++)
{
cnt[(data[i] >> shift) & 0xFF]++;
}
for (int i = 1; i < 256; i++)
{
cnt[i] += cnt[i - 1];
}
for (int i = n - 1; i >= 0; i--)
{
int key = (data[i] >> shift) & 0xFF;
temp[--cnt[key]] = data[i];
}
for (int i = 0; i < n; i++)
{
data[i] = temp[i];
}
}
for (int i = 0; i < n; i++)
{
arr[i] = (int)(data[i] ^ 0x80000000u);
}
free(data);
free(temp);
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
radixsort(arr, n);
printf("\n");
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
free(arr);
return 0;
}
