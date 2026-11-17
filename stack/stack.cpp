#include<iostream>
using namespace std;

const int Max_Size = 5;

class stack{
    private:
            int arr[Max_Size];
            int top;
    public:
            stack(){
                top = -1;
            }
            void push(){
                int value;
                if(top == Max_Size - 1){
                    cout<<"Stack is full"<<endl;
                    return;
                }
                else{
                    cout<<"Enter value to push: ";
                    cin>>value;
                    top++;
                    arr[top] = value;
                    cout<<"Value pushed"<<endl;
                }
            }
            void pop(){
                if(top < 0){
                    cout<<"Stack is empty"<<endl;
                    return;
                }
                int data = arr[top];
                top--;
                cout<<data<<" is popped out of the stack."<<endl;
            }
            void display(){
                cout<<"Stack:"<<endl;
                if(top == -1){
                    cout<<"Stack is empty"<<endl;
                }
                else{
                    for(int i=0;i<=top;i++){
                        cout<<arr[i]<<"\t";
                    }
                }
                cout<<endl;
            }
            void selectionsort(){
                int i, j, temp;
                for(i=0;i<Max_Size-1;i++){
                for(j=i+1;j<=Max_Size-1;j++){
                    if(arr[i] > arr[j]){
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
            }
        }
    }
    cout<<"Sorted Array: "<<endl;
    for(i=0;i<Max_Size;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
            void insertionsort(){
                int i, j, k, temp;
                for(i=1;i<Max_Size;i++){
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
                cout<<"Sorted Array: "<<endl;
                for(i=0;i<Max_Size;i++){
                cout<<arr[i]<<"\t";
                }
                cout<<endl;
            }
};

void insertionsort(){
    int arr[Max_Size];
    
}

int main(){
    stack stackobj;
    int user_choice;
    do{
        cout<<"Welcome. Enter the corresponding number to the function.\n1.Push a value in stack.\n2.Pop a value from stack.\n3.Display all values in stack.\n4.Use Selection Sort to sort array.\n5.Use insert sort to sort array.\n6.Exit the program"<<endl;
        cin>>user_choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Enter a valid value."<<endl;
            continue;
        }
        switch (user_choice){
            case 1:
                    stackobj.push();
                    break;
            case 2:
                    stackobj.pop();
                    break;
            case 3:
                    stackobj.display();
                    break;
            case 4:
                    stackobj.selectionsort();
                    break;
            case 5:
                    stackobj.insertionsort();
                    break;
            case 6:
                    cout<<"Exiting from the program"<<endl;
                    break;
            default:
                    cout<<"An error occured, please try again!"<<endl;
                    break;
        }
    }while(user_choice != 6);
    return 0;
}