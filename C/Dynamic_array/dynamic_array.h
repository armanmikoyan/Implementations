#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

struct DynamicArray
{
    int *arr;
    int size;
    int capacity;
};

void initArray(struct DynamicArray *arr);
void push_back(struct DynamicArray *arr, int elem);
void reserve(struct DynamicArray *arr, int num_of_elem);
int at(struct DynamicArray *arr, int index);
int size(struct DynamicArray *arr);
bool isEmpty(struct DynamicArray *arr);
void printCapacity(struct DynamicArray *arr);
void insert(struct DynamicArray *arr, int pos, int elem);

#endif  
