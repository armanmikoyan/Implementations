#include "dynamic_array.h"
#include <stdlib.h>

void reserve(struct DynamicArray *arr, int num_of_elem)
{
    if (num_of_elem < 1)
    {
        return;
    }

    int *tmp = (int*) malloc(arr->capacity + (sizeof(int) * num_of_elem));
    for (int i = 0; i < arr->size; ++i)
    {
        tmp[i] = arr->arr[i];
    }

    free(arr->arr);
    arr->arr = tmp;
    arr->capacity += (sizeof(int) * num_of_elem);
}
