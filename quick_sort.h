#ifndef QUICK_SORT
#define QUICK_SORT

#include <stdlib.h>
#include <assert.h>

void quickSort(void *arr, size_t len, size_t size, int (*cmp)(const void *, const void *));

#endif
