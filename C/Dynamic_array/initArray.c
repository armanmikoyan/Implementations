#include "dynamic_array.h"
#include <stdlib.h>

void initArray(struct DynamicArray *arr)
{
    arr->arr = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
