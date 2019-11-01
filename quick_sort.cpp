#include "quick_sort.h"

static void swap(void *a, void *b, void *tmp, size_t size)
{
	assert(a);
	assert(b);
	assert(tmp);
	
	memcpy(tmp, a, 	size);
	memcpy(a,   b, 	size);
	memcpy(b, tmp, 	size);
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

void quickSort(void *arr, size_t len, size_t size, int (*cmp)(const void *, const void *))
{
	void *tmp = malloc(size);
	partition(arr, len, size, tmp, cmp);
	free(tmp);
	return;
}
