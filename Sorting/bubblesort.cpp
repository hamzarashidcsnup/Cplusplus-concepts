#include<iostream>
using namespace std;

const int Max = 5;

void sortDescending(int SortedArray[Max]){
    int i, j, temp, flag = 1;
    for(i=0;i<=Max-2;i++){
        for(j=0;j<=Max-2-i;j++){          
            if(SortedArray[j] > SortedArray[j+1]){
                temp = SortedArray[j+1];
                SortedArray[j+1] = SortedArray[j];
                SortedArray[j] = temp;
                flag = 0;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<"Sorted Array(Descending): "<<endl;
    for(i=0;i<Max;i++){
        cout<<"Value at "<<i+1<<" is: "<<SortedArray[i]<<endl;
    }
}

void sortAscending(int SortedArray[Max]){
    int i, j, temp, flag = 1;
    for(i=0;i<=Max-2;i++){
        for(j=0;j<=Max-2-i;j++){          
            if(SortedArray[j] < SortedArray[j+1]){
                temp = SortedArray[j+1];
                SortedArray[j+1] = SortedArray[j];
                SortedArray[j] = temp;
                flag = 0;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<"Sorted Array(Ascending): "<<endl;
    for(i=0;i<Max;i++){
        cout<<"Value at "<<i+1<<" is: "<<SortedArray[i]<<endl;
    }
}

int main(){
    int i, arr[Max];
    for(i=0;i<Max;i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Unsorted Array: "<<endl;
    for(i=0;i<Max;i++){
        cout<<"Value at "<<i+1<<" is: "<<arr[i]<<endl;
    }
    sortAscending(arr);
    sortDescending(arr);
}