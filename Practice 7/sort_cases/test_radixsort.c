#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void radixsort(int* arr, int n)
{
if (n <= 1) return;
uint32_t* data = (uint32_t*)malloc(n * sizeof(uint32_t));
uint32_t* temp = (uint32_t*)malloc(n * sizeof(uint32_t));
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
scanf_s("%d", &n);
int* arr = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++)
{
scanf_s("%d", &arr[i]);
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
