#include <stdio.h>


void sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {10,2,3,4,5,6,7,8,9,1};
    int size = sizeof(arr) / sizeof(int);

    sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d \n", arr[i]);
    }

    return 0;
}

