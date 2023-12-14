#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

void insert(struct DynamicArray* arr,int pos, int elem){
	if(pos >= arr->size){
		printf("err");
	}
	arr->arr[pos] = elem;
 }