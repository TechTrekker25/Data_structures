#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next = NULL;
    }
};

class MyQueue{
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    MyQueue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    void enque(int data){
        Node *n = new Node(data);
        if(head==NULL){
            head = n;
            tail = n;
        }else if(head != NULL){
            tail->next = n;
            tail = n;
        }
        size++;
    }
    void deque(){
        if(head != NULL){
            cout<<head->data<<endl;
            Node *temp = head;
            head = head ->next;
            delete temp;
            size--;          
        }else{
            cout<<"No element to deque"<<endl;
        }
    }
};

int main(){
    MyQueue Q;
    int choice;
    int data;
    do{
        cout<<"***********Queue Implementation using array*******************"<<endl;
        cout<<"1) Enque"<<endl;
        cout<<"2) Deque"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the data: ";
            cin>>data;
            Q.enque(data);
            break;
        case 2:
        cout<<"*********Popped element*********"<<endl;
        Q.deque();
        break;
        case 3:
        cout<<"**********Exit*********"<<endl;
        exit(0);
        default:
            cout<<"Enter valid option"<<endl;
        }

    }while(choice != 3);
}