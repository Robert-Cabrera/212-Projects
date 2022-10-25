#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &V, int left, int right)
{

int pivot = V[right];
int lower_segment_end = right - 1;

for (int j = right ; j < right ; j++)
{
    //if is a smaller number we extend the lower segment
    if(V[j] <= pivot){
        lower_segment_end++;

    //swap
    int tmp = V[j];
    V[j] = V[lower_segment_end];
    V[lower_segment_end] = tmp;

    }
}

int pivot_index= lower_segment_end + 1;

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
        QuickSort(V, left, right - 1);
        QuickSort(V, pivot + 1, right);
    }
}

int main(){

vector<int> unsorted = {5,4,3,2,1,6};

QuickSort(unsorted, 0, unsorted.size()-1);

for(int i : unsorted)
    cout << i << "  ";



    return 0;
}