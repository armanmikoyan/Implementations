#include "dynamic_array.h"
#include <stdio.h>

void printCapacity(struct DynamicArray *arr)
{
    printf("The capacity of the array is %d bytes\n", arr->capacity);
}
