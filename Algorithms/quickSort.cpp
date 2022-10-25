#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &V, int left, int right)
{

int pivot = V[right];
int lower_segment = left - 1;

for (int j = left ; j < right ; j++)
{
    //if is a smaller number we extend the lower segment
    if(V[j] <= pivot){
        lower_segment++;

    //swap
    int tmp = V[j];
    V[j] = V[lower_segment];
    V[lower_segment] = tmp;

    }
}

int pivot_index= lower_segment + 1;

//swap
int tmp = V[right];
V[right] = V[pivot_index];
V[pivot_index] = tmp;

//return the index to recurse
    return pivot_index;

}

void QuickSort(vector <int> &V, int left, int right)
{
    if(left < right)
    {
        int pivot = partition(V, left, right);

        QuickSort(V, left, pivot - 1);
        QuickSort(V, pivot + 1, right);
    }
}
