#include <iostream>

using namespace std;


/*---------------------------------------------------------------
Swaps two elelments of an array
----------------------------------------------------------------*/
void swap(int *x_p, int *y_p)
{
    int temp = *x_p;
    *x_p = *y_p;
    *y_p = temp;
}

/*---------------------------------------------------------------
printing all array elements ina. single line
----------------------------------------------------------------*/
void print_array(int arr[], int size)
{
    for (int i = 0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*---------------------------------------------------------------
Bubble sorting algorithm
----------------------------------------------------------------*/
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0 ; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
        print_array(arr, size);
    }
}

/*---------------------------------------------------------------
main function
----------------------------------------------------------------*/
int main()
{
    int arr[] = {64, 25, 12, 22, 11, 5, 80, 100, 1};
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, size_arr);
    
    return 0;
}