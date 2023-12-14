#include <iostream>

void countingSort(int* arr, int size)
{
    int max = *std::max_element(arr, arr + size);
    int* count = new int[max + 1]{};

    // counting each elem
     for (int i = 0; i < size; ++i)
     {
          ++count[arr[i]];
     }

    int k = 0;
    for(int i = 0; i <= max; ++i)
    {
        while(count[i] > 0)
        {
            arr[k++] = i;
            count[i]--;
        }
    }
    
    delete[] count;
}


// stable counting sort 
void countingSortStable(int* arr, int size) 
{
    int max = *std::max_element(arr, arr + size);
    int* count = new int[max + 1]{};
    int* res = new int[size]{};
    
    for (int i = 0; i < size; ++i)
    {
        ++count[arr[i]];
    }

    for (int i = 1; i <= max; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        res[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; i < size; ++i)
    {
        arr[i] = res[i];
    }

    delete[] count;
    delete[] res;
}


int main()
{
    int arr[]{5, 5, 3, 2, 1, 1, 1, 1, 5, 7, 6, 5, 10};
    int size = sizeof(arr) / sizeof(int);
    countingSortStable(arr, size);

    for(auto it : arr)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}