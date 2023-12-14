#include "dynamic_array.h"
#include <stdlib.h>

void push_back(struct DynamicArray *arr, int elem)
{
    if (arr->arr == NULL)
    {
        arr->arr = (int*) malloc(sizeof(int));
        arr->capacity = sizeof(int);
    }

    if (arr->size * sizeof(int) == arr->capacity)
    {
        int *tmp = (int*) malloc(arr->capacity * 2);
        for (int i = 0; i < arr->size; ++i)
        {
            tmp[i] = arr->arr[i];
        }

        free(arr->arr);
        arr->arr = tmp;
        arr->capacity = arr->capacity * 2;
    }

    arr->arr[arr->size] = elem;
    arr->size++;
}
