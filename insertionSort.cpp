#include <iostream>

using namespace std;

void insertionSort(int arr[],int n){

    int i,j,key;

    for (i = 1 ; i <= (n-1) ; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void display(int *arr, int n){

    for (int i = 0 ; i < n ; i++){

        cout << "[" << arr[i] << "]";
        if(i  < n-1){
            cout << ", ";
        }
    }
}

void delete_dup(int arr[], int &n) {

    int j = 0;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];

    arr[j++] = arr[n - 1];

    n = j;
}

int main(){

    int arr[] = {5,4,3,2,1,1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nBefore sorting: \n" << "\t" ; display(arr,n);

    insertionSort(arr,n);

    cout << "\nAfter sorting: \n" << "\t" ; display(arr,n);

    delete_dup(arr, n);

    cout << "\nAfter removing duplicates: ->" <<  " new size: " << n << "\n\t" ; display(arr,n);

    return 0;
}