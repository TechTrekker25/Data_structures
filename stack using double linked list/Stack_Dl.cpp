#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Stack_DL{
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    Stack_DL(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    int getSize(){
        return size;
    }
    void push(int data){
        Node *n = new Node(data);
        if(head==NULL){
            head = n;
            tail = n;
            size++;
        }else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    int pop(){
        if(tail == NULL){
            cout<<"stack is empty"<<endl;
        }else if(tail != NULL)
        {
        cout<<tail->data<<endl;
        Node *temp = tail;
        tail = tail->prev;
        delete temp;
        }
        return 0;
    }
};

int main(){
    Stack_DL S;
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
        S.pop();
        break;
        case 3:
        cout<<"**********Exit*********"<<endl;
        exit(0);
        default:
            cout<<"Enter valid option"<<endl;
        }

    }while(choice != 3);
}