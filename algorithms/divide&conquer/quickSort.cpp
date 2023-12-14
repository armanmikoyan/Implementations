#include <iostream>

//pivot (median of tree method)
int median_of_tree(int* arr, int st, int en)
{
    int mid = st + (en - st ) / 2;

    if (arr[st] > arr[mid])
    {
        std::swap(arr[st], arr[mid]);
    }
    if (arr[mid] > arr[en])
    {
        std::swap(arr[mid], arr[en]);
    }

    if (arr[st] > arr[mid])
    {
        std::swap(arr[st], arr[mid]);
    }
    return mid;
}

int partition_pivot_median_of_tree(int* arr, int start, int end)
{
    int median_pivid = median_of_tree(arr, start, end);
    std::swap(arr[median_pivid], arr[end]);

    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;  
}


// pivot start
int partition_pivot_start(int* arr, int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (i < end && arr[i] <= pivot)
        {
            i++;
        }

        while (j >= start && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[start], arr[j]);
    return j;
}


// pivot end
int partition_pivot_end(int* arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;  
}


void QuickSort(int* arr, int start, int end)
{
    if (start < end)
    {
        int pivotid = partition_pivot_median_of_tree(arr, start, end);
        QuickSort(arr, start, pivotid - 1);
        QuickSort(arr, pivotid + 1, end);
    }
}

int main()
{
    int arr[]{5, 3, 2, 1, 2, 4, 5, 3, 5, 0};
    int size = sizeof(arr) / sizeof(int);
    QuickSort(arr, 0, size - 1);
    for(auto it : arr)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}
