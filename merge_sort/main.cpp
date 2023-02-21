// merge sort
// @ Reza Roofegari

#include <iostream>

using namespace std;
/*---------------------------------------------------------------
Declare functions
----------------------------------------------------------------*/
void print_array(int arr[], int arr_size);


/*---------------------------------------------------------------
merge function
----------------------------------------------------------------*/
void merge(int arr[],
int const left,
int const mid,
int const right)
{
    // size of sub arrays
    // Note: not add 1 to the size of the sub array 2
    // since the mid is on the side of the sub array one.
    int size_sub_array_left = mid - left + 1; 
    int size_sub_array_right = right - mid;
    
    // Create temp sub arrays
    int *sub_array_left = new int[size_sub_array_left];
    int *sub_array_right = new int[size_sub_array_right];
    
    // copy data to temp array left
    for (int i = 0; i < size_sub_array_left; i++)
    {
        sub_array_left[i] = arr[left + i];
    }
    
    // copy data to temp array right
    for (int i = 0; i < size_sub_array_right; i++)
    {
        sub_array_right[i] = arr[mid + 1 + i];
    }
    
    // temp indeces for both sub arrays
    int ind1 = 0;
    int ind2 = 0;
    int ind_merge = left;
    
    
    while (ind1 < size_sub_array_left && ind2 < size_sub_array_right)
    {
        if (sub_array_left[ind1] <= sub_array_right[ind2])
        {
            arr[ind_merge] = sub_array_left[ind1];
            ind1++;
        }
        else
        {
            arr[ind_merge] = sub_array_right[ind2];
            ind2++;
        }
        
        ind_merge++;
    }
    
    // copy remaining of the sub array left to the original array if anything left
    while (ind1 < size_sub_array_left)
    {
        arr[ind_merge] = sub_array_left[ind1];
        ind1++;
        ind_merge++;
    }
    
    // copy remaining of the sub array right to the original array if anything left
    while (ind2 < size_sub_array_right)
    {
        arr[ind_merge] = sub_array_right[ind2];
        ind2++;
        ind_merge++;
    }
    
    
    // delete sub arrays from the heap memory to prevent memory leak
    delete[] sub_array_left;
    delete[] sub_array_right;
}

/*---------------------------------------------------------------
helper merge sort function
----------------------------------------------------------------*/
void merge_sort_sort(int arr[], int start, int end)
{
    // recurrsive check
    if (start >= end)
    {
        return;
    }
    
    int mid = start + (end-start)/2;
    
    // first half recurrsive call
    merge_sort_sort(arr, start, mid);
    
    // second half recurrsive call
    merge_sort_sort(arr, mid+1, end);
    
    // merge function
    merge(arr, start, mid, end);
    
}


/*---------------------------------------------------------------
Merge sort function
----------------------------------------------------------------*/
void merge_sort(int arr[], int arr_size)
{
    int start = 0;
    int end = arr_size - 1;
    
    merge_sort_sort(arr, start, end);
}

/*---------------------------------------------------------------
main function
----------------------------------------------------------------*/
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 1, 10, 60, 100, 200, 256, 4};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Given array is: \n";
    print_array(arr, arr_size);
    
    merge_sort(arr, arr_size);
    
    cout << "\n";
    cout << "Sorted array is: \n";
    print_array(arr, arr_size);
    cout << "\n";
    
    return 0;
}


/*---------------------------------------------------------------
Helper function to print an array
----------------------------------------------------------------*/
void print_array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
}