#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void selectionSort(int arr[], int n)
{
    int min;

    for(int i=0; i < n-1; i++)
    {
       min = i;
       for(int j = i+1; j < n; j++){
           if(arr[j] < arr[min])  
            {
                min = j;
            }
       }
       swap(&arr[min],&arr[i]); 
       /*
        tmp= arr[i]
        arr[i] = arr[min]
        arr[min] = tmp
       */
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr [] = {21,10,1,3,5,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    selectionSort(arr,n);
    cout << "Sorted arr: ";
    printArray(arr,n);

    return 0;
}