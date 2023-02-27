// quick sort
// @ Reza Roofegari nejad

#include <iostream>

using namespace std;

/*---------------------------------------------------------------
Declare functions
----------------------------------------------------------------*/
void print_array(int arr[], int size);

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
Find left and right elements based on pivot element swap them
 until end. Then put the pivot elelment in its correct place
 within the array
----------------------------------------------------------------*/
void find_swap_left_right(int arr[],
int *left,
int *right,
int *pivot,
int high)
{
    int temp_left = *left;
    int temp_right = *right;
    bool swap_flag = false;
    
    while (*left <= *right)
    {
        // find the left number which is greater than pivot number
        while ((arr[*left] < *pivot) && (*left < *right))
        {
            (*left)++;
        }
        
        // find the right number which is smaller than pivot number
        while ((arr[*right] > *pivot) && (*right > *left))
        {
            (*right)--;
        }
        
        // swap left and right
        if (*left < *right)
        {
            swap(arr[*left], arr[*right]);
            
            swap_flag = true;
            temp_left = *left;
            temp_right = *right;
        }
        else if (*left == *right)
        {
            (*right)--;
            
            if (*left == high)
            {
                swap_flag = true;
                
                temp_left = *left;
                temp_right = *right;
            }
            
        }
    }
    
    *left = temp_left;
    *right = temp_right;
    
    // put pivot in its correct place within the array
    if (swap_flag)
    {
        swap(pivot, &arr[*left]);
    }
}

/*---------------------------------------------------------------
quick sort helper recurrsive function
note: This function takes first element as the pivot
----------------------------------------------------------------*/
void quick_sort_sort(int arr[], int low, int high)
{
    
    if(high <= low)
    {
        return;
    }
    
    int *pivot = &arr[low];
    int left = low + 1;
    int right = high;
    
    // find left and right elements and swap them until
    // left passes the right. Then, swap pivot with the
    // left elemnet index
    find_swap_left_right(arr, &left, &right, pivot, high);
    
    // recurssive call of quick sort on the left array of pivot
    quick_sort_sort(arr, low, left - 1);
    
    // recurssive call of quick sort on the right array of pivot
    quick_sort_sort(arr, left + 1, high);
}

/*---------------------------------------------------------------
quick sort main function
----------------------------------------------------------------*/
void quick_sort(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    
    // recurrsive function
    quick_sort_sort(arr, low, high);
}


/*---------------------------------------------------------------
main functions
----------------------------------------------------------------*/
int main()
{
    int arr[] = {5, 3, 6, 9, 2, 4, 7, 8};
    int size = sizeof(arr) /sizeof(arr[0]);
    
    cout << "Given array is" << endl;
    print_array(arr, size);
    
    quick_sort(arr, size);
    
    cout << "Sorted array is" << endl;
    print_array(arr, size);
    
    return 0;
}

/*---------------------------------------------------------------
print array
----------------------------------------------------------------*/
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}


