#include "dynamic_array.h"
#include <stdbool.h>
#include <stdio.h>

bool isEmpty(struct DynamicArray *arr)
{
    return arr->size == 0;
}
