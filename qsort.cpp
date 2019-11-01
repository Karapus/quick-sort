#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void swap(void *a, void *b, void *tmp, size_t size)
{
	assert(a);
	assert(b);
	assert(tmp);
	
	memcpy(tmp, a, 	size);
	memcpy(a,   b, 	size);
	memcpy(b, tmp, 	size);
}

int intCmp(const void *a, const void *b)
{
	return *((const int *)a) - *((const int *)b);
}

static void partition(void *arr, size_t len, size_t size, void *tmp, int (*cmp)(const void *, const void *))
{
	assert(arr);
	assert(size);

	if (len <= 1) return;

	swap((char *)arr + size * (rand() % len), arr, tmp, size);
	char *cur_l = (char *)arr + size;
	char *cur_r = (char *)arr + size * (len - 1);
	
	while (cur_l <= cur_r)
	{
		if 	(cmp(cur_l, arr) < 0) cur_l += size;
		else if (cmp(cur_r, arr) > 0) cur_r -= size;
		else 
		{
			swap(cur_l, cur_r, tmp, size);
			cur_l += size, cur_r -= size;
		}
	}
	
	return 	partition(arr, (cur_r - (char *)arr) / size + 1, size, tmp, cmp),
		partition(cur_l, len - (cur_l - (char *)arr) / size, size, tmp, cmp);
}

void qsort(void *arr, size_t len, size_t size, int (*cmp)(const void *, const void *))
{
	void *tmp = malloc(size);
	partition(arr, len, size, tmp, cmp);
	free(tmp);
	return;
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
	free(a);
	return 0;
}
