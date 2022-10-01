#include <iostream>

using namespace std;

int BinarySearch(int arr[], int left, int right, int target)
{

if(right >= left)
{
    int m = left + (right-left)/2;

    if(arr[m] == target)
    {
        return m;
    }
    
    if(arr[m] > target)
    {
        return BinarySearch(arr, left, m-1, target);
    }

    else
    {
         return BinarySearch(arr, m + 1, right, target);
    }
}

    return -1;

}
