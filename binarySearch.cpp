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
int main(){

int arr[5] = {4,5,6,7,8};

int r = ( sizeof(arr) / sizeof(arr[0]) );
int l = 0;
int target = 4;

int result = BinarySearch(arr, l, r-1, target);

(result == -1) ? cout << "Element is not in the list \n" 
               : cout << "Element is in position " << result + 1 << "! \n";

    return 0;
}