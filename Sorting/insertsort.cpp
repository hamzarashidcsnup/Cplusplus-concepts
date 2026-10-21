#include<iostream>
using namespace std;

const int SIZE = 5;

void InsertSortingDescending(int arr[SIZE]){
    int i, j, k, temp;
    for(i=1;i<SIZE;i++){
        for(j=0;j<i;j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                for(k=i;k>j;k--){
                    arr[k] = arr[k-1];
                }
            arr[j] = temp;
            break;
            }
        }
    }
    cout<<"SORTED(Descending): "<<endl;
    for(i=0;i<SIZE;i++){
        cout<<arr[i]<<endl;
    }
}

void InsertSortingAscending(int arr[SIZE]){
    int i, j, k, temp;
    for(i=1;i<SIZE;i++){
        for(j=0;j<i;j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                for(k=i;k>j;k--){
                    arr[k] = arr[k-1];
                }
            arr[j] = temp;
            break;
            }
        }
    }
    cout<<"SORTED(Ascending): "<<endl;
    for(i=0;i<SIZE;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[SIZE], i;
    for(i=0;i<SIZE;i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"UNSORTED: "<<endl;
    for(i=0;i<SIZE;i++){
        cout<<arr[i]<<endl;
    }
    InsertSortingAscending(arr);
    InsertSortingDescending(arr);
    return 0;
}