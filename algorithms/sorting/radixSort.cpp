#include <iostream>

void countingSort(int* arr, int size, int exp) 
{
    const int base = 10;
    int* res = new int[size];
    int count[base]{};

     for (int i = 0; i < size; ++i)
     {
        ++count[(arr[i] / exp) % 10];
     }


    for (int i = 1; i < base; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        res[count[(arr[i] / exp) % base] - 1] = arr[i];
        --count[(arr[i] / exp) % base];
    }

    for (int i = 0; i < size; ++i)
    {
        arr[i] = res[i];
    }

    delete[] res;
}



void radixSort(int* arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
   
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, size, exp);
    }

}

int main()
{
    int arr[]{512312, 512122, 31111, 22222, 13334, 13423, 17879, 1987, 566, 75567, 6555, 55, 160};
    int size = sizeof(arr) / sizeof(int);
    radixSort(arr, size);

    for(auto it : arr)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}
