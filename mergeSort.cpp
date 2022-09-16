#include <iostream>
#include <vector>

using namespace  std;

vector<int> mergeSort(const vector<int>& arr){

    vector<int> vec = arr;
    int n = vec.size();

    if (n < 2)
        return arr;

    else
    {
        int m = (n / 2);

        vector<int> l(vec.begin(),vec.begin() + m);
        vector<int> r(vec.begin()+ m, vec.begin() + n);


        l = mergeSort(l);
        r = mergeSort(r);

        unsigned int i= 0;
        unsigned int j= 0;
        unsigned int index = 0;

        while (i < l.size() && j < r.size()) {
            if (l[i] < r[j]) {
                vec[index]=l[i];
                i++;
            }

            else {
                vec[index] = r[j];
                j++;
            }
            index++;
        }

        while (i < l.size()) {
            vec[index] = l[i];
            i++;
            index++;
        }

        while (j < r.size()) {
            vec[index]=r[j];
            j++;
            index++;
        }

    }

    return vec;

}

void display(vector<int> arr, int n){

    for (int i = 0 ; i < n ; i++){

        cout << "[" << arr[i] << "]";
        if(i  < n-1){
            cout << ", ";
        }
    }
}