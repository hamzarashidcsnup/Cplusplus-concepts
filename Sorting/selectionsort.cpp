#include<iostream>
using namespace std;

const int MAX = 5;

void DescendingSort(int SortArr[MAX]){
    int i, j, temp;
    for(i=0;i<=MAX-1;i++){
        for(j=i+1;j<=MAX-1;j++){
            if(SortArr[i] < SortArr[j]){ //5,8,3,2,1
                temp = SortArr[j];
                SortArr[j] = SortArr[i];
                SortArr[i] = temp;
            }
        }
    }
    cout<<"Sorted Array(Descending order): "<<endl;
    for(i=0;i<MAX;i++){
        cout<<"Value at "<<i+1<<" is: "<<SortArr[i]<<endl;
    }
}

void AscendingSort(int SortArr[MAX]){
    int i, j, temp;
    for(i=0;i<=MAX-1;i++){
        for(j=i+1;j<=MAX-1;j++){
            if(SortArr[i] > SortArr[j]){ //5,8,3,2,1
                temp = SortArr[j];
                SortArr[j] = SortArr[i];
                SortArr[i] = temp;
            }
        }
    }
    cout<<"Sorted Array(Ascending order): "<<endl;
    for(i=0;i<MAX;i++){
        cout<<"Value at "<<i+1<<" is: "<<SortArr[i]<<endl;
    }
}

int main(){
    int i, arr[MAX];
    for(i=0;i<MAX;i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Unsorted Array: "<<endl;
    for(i=0;i<MAX;i++){
        cout<<"Value at "<<i+1<<" is: "<<arr[i]<<endl;
    }
    DescendingSort(arr);
    AscendingSort(arr);
    return 0;
}