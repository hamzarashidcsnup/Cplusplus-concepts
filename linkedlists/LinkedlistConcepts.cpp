#include<iostream>
using namespace std;

class linklist{
    private:
            struct node{
                int data;
                node *link;
            }*p;
    public:
            linklist();
            void append(int num);
            void addatbegining(int num);
            void addafter(int loc, int num);
            void del(int num);
            void display();
};

linklist::linklist(){
    p = NULL;
}

void linklist::append(int num){
    node *temp, *r;
    if(p == NULL){
        temp = new node;
        temp->data = num;
        temp->link = NULL;
        p = temp;
    }
    else{
        temp = p;
        while(temp->link != NULL){
            temp = temp->link;
        }
            r = new node;
            r->data = num;
            r->link = NULL;
            temp->link = r;
    }
}

void linklist::addatbegining(int num){
    node *temp;
    temp = new node;
    temp ->data = num;
    temp ->link = p;
    p = temp;
}

void linklist::addafter(int loc, int num){
    node *temp, *r;
    temp = p;
    for(int i=0;i<loc-1;i++){
        temp = temp->link;
        if(temp == NULL){
        cout<<"There are less than "<<loc<<" elements."<<endl;
        }
    }

    r = new node;
    r->data = num;
    r->link = temp->link; 
    temp->link = r;
}

void linklist::del(int num){
    node *temp, *old;
    temp = p; //temps also points where p is pointing
    while(temp != NULL){
        if(temp->data == num){
            if(temp == p){
                p = temp->link;  /*when u equal to link, it will jump to the  next node and point it,
                                  hence it will traverse to the next node*/
            }
            else{
                old->link = temp->link;
            }
            delete temp;
            return; //exit while
        }
        else{
            old = temp;
            temp = temp->link;
        }
    }
}

void linklist::display(){
    node *temp = p;
    while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->link;
    }
}

int main(){
    linklist linklistobj;
    string user_choice;
    int user_choice_int;
    do{
        cout<<"Welcome! Enter the number against the desired operation.\n1.Append a number.\n2.Delete a number\n3.Add a number at beginning.\n4.Add a number after another number.\n5.Display the data.\n6.Exit from the program.\n";
        cin>>user_choice_int;
        switch(user_choice_int){
            case 1:
                    do{
                        cout<<"Do you want to append a number?: ";
                        cin>>user_choice;
                        if(user_choice == "yes" || user_choice == "Yes" || user_choice == "YES"){
                            int num_to_append = 0;
                            cout<<"Enter number to append: ";
                            cin>>num_to_append;
                           if (cin.fail()){
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "Invalid input, please try again!" << endl;
                                continue;
                            }
                            linklistobj.append(num_to_append);
                        }
                    }while(user_choice != "no");
                    break;
            case 2:
                    int num_to_be_deleted;
                    cout<<"Enter number you want to delete: ";
                    cin>>num_to_be_deleted;
                    linklistobj.del(num_to_be_deleted);
                    cout<<num_to_be_deleted<<" is deleted from the data."<<endl;
                    break;
            case 3:
                    do{
                        cout<<"Do you want to add a number at the beginning? ";
                        cin>>user_choice;
                        if(user_choice == "yes" || user_choice == "Yes" || user_choice == "YES"){
                            int num_to_add_at_beginning;
                            cout<<"Enter the number you want to add at the beginning: ";
                            cin>>num_to_add_at_beginning;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout<<"Invalid number, please try again: ";
                                continue;
                            }
                            linklistobj.addatbegining(num_to_add_at_beginning);
                        }
                    }while(user_choice != "no");
                    break;
            case 4:
                    int location, num_to_be_added;
                    cout<<"Enter the number you want to add: ";
                    cin>>num_to_be_added;
                    cout<<"Enter the location at which you want the number to be added: ";
                    cin>>location;
                    linklistobj.addafter(location, num_to_be_added);
                    break;
            case 5:
                    linklistobj.display();
                    cout<<"\n";
                    break;
            case 6:
                    cout<<"Exiting..."<<endl;
                    break;
            default:
                    cout<<"Error, please enter a valid option."<<endl;
                    break;
        }
    }while(user_choice_int != 6);
    return 0;
}