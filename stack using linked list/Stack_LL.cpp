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

class Stack_LL{
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    Stack_LL(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    void push(int data){
        Node *n = new Node(data);
        if(head==NULL){
            head = n;
            tail = n;
        }else if(head != NULL){
            n->next = head;
            head = n;
        }
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
        }else if(head != NULL){
            cout<<head->data<<endl;
            Node *temp = head;
            head=head->next;
            delete temp;
        }      
    }
};

int main(){
    Stack_LL S;
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