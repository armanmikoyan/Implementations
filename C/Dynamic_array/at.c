#include "dynamic_array.h"
#include <stdio.h>

int at(struct DynamicArray *arr, int index)
{
    if (index >= arr->size)
    {
        printf("Index is out of range\n");
        return -1;
    }

    return arr->arr[index];
}
