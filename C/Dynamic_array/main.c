#include "dynamic_array.h"
#include <stdio.h>

int main()
{
    struct DynamicArray arr;
    initArray(&arr);
    push_back(&arr, 10);
    push_back(&arr, 20);
    return 0;
}
