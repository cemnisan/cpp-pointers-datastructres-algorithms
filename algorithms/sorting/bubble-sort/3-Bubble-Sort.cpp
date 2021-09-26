#include <iostream>
using namespace std;


void swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void bubbleSort(int arr[], int n){
    int i,j;

    for(i=0; i<n-1; i++){
        bool isSorted = true;

        for (j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                isSorted = false;
                swap(arr[j],arr[j+1]);
            }
        }
        if(isSorted){
            break;
        }

    }
}

void printerArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){

    int arr[] = {7,5,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);
    cout << "bubble sort: " << endl;
    printerArray(arr,n);

    return 0;
}