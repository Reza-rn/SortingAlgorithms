#include <iostream>

using namespace std;

// Swap function
void swap(int *x_p, int *y_p)
{
    int temp = *x_p;
    *x_p = *y_p;
    *y_p = temp;
}

void selection_sort(int arr[], int size)
{
    int i, j, min_ind;
    // One by one move boundary and find minimimum and put at the beginning
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in the unsorted array
        min_ind = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        
        // Swap the found minimum element with the first element in selection part of the array
        if (min_ind != i)
        {
            swap(&arr[min_ind], &arr[i]);
        }
    }
}


void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, size);
    
    cout << "Sorted array: \n";
    print_array(arr, size);
    
    
    return 0;
}