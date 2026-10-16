#include<iostream>           //Binary is used when the array is in order, no randomizing
using namespace std;         //example: arr = {1,2,3,4,5};

const int Max = 5;
//Optional function to sort array if user enters unsorted, otherwise user is bound to enter sorted values
void sortArray(int tempArr[Max]){
    int i, j, temp;
    for(i=0;i<=Max-1;i++){
        for(j=i+1;j<=Max-1;j++){
            if(tempArr[i] > tempArr[j]){
                temp = tempArr[i];
                tempArr[i] = tempArr[j];
                tempArr[j] = temp;
            }
        }
    }
}

void binarysearch(int temparr[Max], int tempnumtoFind){
    int lower = 0, upper = Max - 1, mid = 0, flag = 1;
    for(mid=(lower+upper)/2;lower<=upper;mid=(lower+upper)/2){
        if(temparr[mid] == tempnumtoFind){
            cout<<"Number "<<tempnumtoFind<<" is located at "<<mid<<" index in the array."<<endl;
            flag = 0;
            break;
        }
        else if(tempnumtoFind > temparr[mid]){   //{2, 4 ,6 ,8 ,10}
            lower = mid + 1; //since array is in order, if the num to find is less than the num at the
        }                    //arr[mid] location, then it means that the num to find is after the arr[mid].
        else{
            upper = mid - 1;
        }
    }
    if(flag){
        cout<<"Number is not in the given array."<<endl;
    }
}

int main(){
    int arr[Max], i, numtoFind, sortedArray;
    for(i=0;i<Max;i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Enter the number you want to find: ";
    cin>>numtoFind;
    sortArray(arr);
    binarysearch(arr, numtoFind);
    return 0;
}