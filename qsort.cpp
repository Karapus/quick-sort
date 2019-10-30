#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void swap(void* a, void* b, size_t size)
{
	assert(a);
	assert(b);
	
	static void *tmp = malloc(size);
	memcpy(tmp, a, 	size);
	memcpy(a,   b, 	size);
	memcpy(b, tmp, 	size);
}

int intCmp(const void *a, const void *b)
{
	return *((const int *)a) - *((const int *)b);
}

void qsort(int* arr, size_t len, size_t size, int cmp(const void *, const void *))
{
	assert(arr);
	assert(size);

	if (len <= 1) return;

	swap(arr + rand() % len, arr, size);
	int* cur_l = arr + 1;
	int* cur_r = arr + (len - 1);
	while (cur_l <= cur_r)
	{
		if 	(cmp(cur_l, arr) < 0) cur_l ++;
		else if (cmp(cur_r, arr) > 0) cur_r --;
		else swap(cur_l ++, cur_r --, size);
	}

	for (size_t i = 0; i < len; printf("%d, ", ((int*)arr)[i++]))
		;
	putchar('\n');
	return 	qsort(arr, cur_r - arr + 1, size, cmp),
		qsort(cur_l, len - (cur_l - arr), size, cmp);
}

int main()
{
	size_t len = 0;
	scanf("%ld", &len);
	int* a = (int*) calloc(sizeof(*a), len);
	for (int *el  = a; el < a + len; scanf("%d", el++))
		;
	qsort(a, len, sizeof(*a), intCmp);
	for (size_t i = 0; i < len; printf("%d, ", a[i++]))
		;
	putchar('\n');
}
