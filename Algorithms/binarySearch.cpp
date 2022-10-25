#include <iostream>

using namespace std;

int BinarySearch(int arr[], int left, int right, int target)
{

if(right >= left)
{
    int mid = left + (right-left)/2;

    if(arr[mid] == target)
    {
        return mid;
    }
    
    if(arr[mid] > target)
    {
        return BinarySearch(arr, left, mid-1, target);
    }

    else
    {
         return BinarySearch(arr, mid + 1, right, target);
    }
}

    return -1;

}
