#include <iostream>
using namespace std;

class StackArray{
    private:
    int size ;
    int *StackAr;
    int top;
    public:
    StackArray(int size){
        this->size = size;
        StackAr = new int(size);
        top = -1;
    }
    void resize(){
        int NewSize = size * 2;
        int *NewStackar = new int(NewSize);
        for(int i = 0;i<NewSize;i++){
            NewStackar[i] = StackAr[i];      
        }
        StackAr = NewStackar;
        size = NewSize;

    }
    void push(int data){
        if(top==size-1){
            resize();
        }else{
            StackAr[++top] = data;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"The stack is empty"<<endl;
            return -1;
        }else{
            return StackAr[top--];
        }
    }
    ~StackArray(){
        delete[] StackAr;
    }
};

int main(){
    StackArray S(3);
    int choice;
    int data;
    do{
        cout<<"***********Stack Implementation using array*******************"<<endl;
        cout<<"1) Push"<<endl;
        cout<<"2) Pop"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the data: ";
            cin>>data;
            S.push(data);
            break;
        case 2:
        cout<<"*********Popped element*********"<<endl;
        cout<<S.pop()<<endl;
        break;
        case 3:
        cout<<"**********Exit*********"<<endl;
        exit(0);
        default:
            cout<<"Enter valid option"<<endl;
        }

    }while(choice != 3);
}