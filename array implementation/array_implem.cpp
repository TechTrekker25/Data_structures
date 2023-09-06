#include <iostream>
using namespace std;

#define maxsize 50
int size = 0;
int arr[maxsize];

void insertAtpos(int po,int da){
    for(int i = size -1 ; i>=po;i--){
        arr[i+1] = arr[i];
        }
        arr[po] = da;
        size++;
        cout<<da <<" is inserted at "<< po<<endl;
}

void showAll(){
    for(int i=0; i<size;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void deleteAtpos(int po){
    for(int i = po; i<size-1;i++){
            arr[i] = arr[i+1];
    }
    size--;
    cout<<"This is the updated array"<<endl;
    showAll();
}

int main(){
    int choice,data,pos;
    do{
        cout<<"***********Array Implementation**********"<<endl;
        cout<<"1) Insert at the end"<<endl;
        cout<<"2) Insert at this position"<<endl;
        cout<<"3) Delete at the end"<<endl;
        cout<<"4) Show all the elements"<<endl;
        cout<<"5) Quit"<<endl;
        cout<<"Enter the choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<"***********Insertion************"<<endl;
        if(size == maxsize){
            cout<<"Array is full";
        }else{
            cout<<"Enter the element: ";
            cin>>data;
            arr[size] = data;
            size++;
        }
        break;
        case 2:
        cout<<"************Insertion at position*****************"<<endl;
        cout<<"Enter the position: ";
        cin>>pos;
        if(pos<0 || pos>maxsize){
            cout<<"Enter valid position"<<endl;
        }else{
            cout<<"Enter the data: ";
            cin>>data;
            insertAtpos(pos,data);
        }
        break;
        case 3:
        cout<<"**************Deletion at position*******************"<<endl;
        cout<<"Enter the position: ";
        cin>>pos;
        if(pos<0 || pos>maxsize){
            cout<<"Enter valid position"<<endl;
        }else{
            deleteAtpos(pos);
        }
        break;
        case 4:
        showAll();
        break;
        case 5:
        exit(0);
        default:
            cout<<"Enter the correct choice"<<endl;
        }
    }while(choice != 5);
    return 0;
}
