#include<iostream>
using namespace std;

const int SIZE = 5;

int splitAscending(int arr[SIZE], int lower, int upper){
    int i, p, q, temp;
    i = arr[lower];
    p = lower + 1;
    q = upper;
    while(q >= p){
        while(p <=upper && arr[p] <= i){
            p++;
        }
        while(arr[q] > i){
            q--;
        }
        if(q > p){
            temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    temp = arr[lower];
    arr[lower] = arr[q];
    arr[q] = temp;
    return q;
}
int splitDescending(int arr[SIZE], int lower, int upper){
    int i, p, q, temp;
    i = arr[lower];
    p = lower + 1;
    q = upper;
    while(q >= p){
        while(p <= upper && arr[p] >= i){
            p++;
        }
        while(arr[q] < i){
            q--;
        }
        if(q > p){
            temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    temp = arr[lower];
    arr[lower] = arr[q];
    arr[q] = temp;
    return q;
}

void quicksortAscending(int arr[SIZE], int lower, int upper){
    if(lower < upper){
        int i = splitAscending(arr, lower, upper);
    quicksortAscending(arr, lower, i-1);
    quicksortAscending(arr, i+1, upper);
    }
}

void quicksortDescending(int arr[SIZE], int lower, int upper){
    if(lower < upper){
        int i = splitDescending(arr, lower, upper);
    quicksortDescending(arr, lower, i-1);
    quicksortDescending(arr, i+1, upper);
    }
}

int main(){
    int arr[SIZE], i;
    for(i=0;i<SIZE;i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Unsorted Array: "<<endl;
    for(i=0;i<SIZE;i++){
        cout<<i+1<<": "<<arr[i]<<endl;
    }
    quicksortAscending(arr, 0, SIZE-1);
    cout<<"Sorted Array(Ascending): "<<endl;
    for(i=0;i<SIZE;i++){
        cout<<i+1<<": "<<arr[i]<<endl;
    }
    quicksortDescending(arr, 0, SIZE-1);
    cout<<"Sorted Array(Descending): "<<endl;
    for(i=0;i<SIZE;i++){
        cout<<i+1<<": "<<arr[i]<<endl;
    }
    return 0;
}