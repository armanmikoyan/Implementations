#include <stdio.h>

void forEach(int* arr, int size, void (*callback)(int)){
  for(int i = 0; i < size; ++i){
     callback(arr[i]);
   }
 }

void printFF(int arr_elem){
 printf("%d \n", arr_elem);
}

int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int len = sizeof(arr) / sizeof(int);
  forEach(arr,len,printFF);
 return 0;
}
