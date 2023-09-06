#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data=data;
        prev = NULL;
        next = NULL;
    }
};

class D_list{
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    D_list(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    void prepend(int data){
        Node *n = new Node(data);
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            n->next=head;
            head->prev = n;
            head = n;
        }
        size++;
    }
    void append(int data){
        Node *n = new Node(data);
        if(head == NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            n->prev = tail;
            tail=n;
        }
        size++;
    }
    void InsertAt(int pos, int data){
        if(pos<1 || pos>size+1){
            cout<<"Enter valid position"<<endl;
        }else if(pos==1){
            prepend(data);
       
        }else if(pos==size+1){
            append(data);
  
        }else if(head != NULL){
            Node *n = new Node(data);
            Node *curr = head;
            for(int i=1;i<pos;i++){
                curr= curr->next;
            }
           curr->prev->next=n;
           n->prev = curr->prev;
           n->next = curr;
           curr->prev = n;
        size++;
        }
    }
    void DeleteFirst(){
        if(head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
            size--;
        }else if(head->next != NULL){
            head = head->next;
            delete head->prev;
            head->prev = NULL;  
            size--;
        }
    }
    void DeleteLast(){
        if(head->next==NULL){
            delete head;
            head = NULL;
            tail = NULL;
            size--;
        }else if(head->next != NULL){
            tail = tail->prev;
            delete tail->next;
            size--;
        }
    }
    void DeleteAt(int pos){
        if(pos<1 || pos>size){
            cout<<"Enter valid position"<<endl;
        }else if(pos == 1){
            DeleteFirst();
        }else if(pos==size){
            DeleteLast();
        }else{
            Node *curr = head;
            for(int i=1;i<pos;i++){
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            size--;
        }
    }
    void RevDisplay(){
        Node *temp = tail;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
    void Display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
            tail->next = NULL;
        }
        cout<<endl;
    }
    ~D_list(){
        Node *temp;
        while(head != NULL){
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main(){
    D_list l;
    int choice;
    int data,pos;
    do{
        cout<<"***************Linked List***************"<<endl;
        cout<<"1) Prepend"<<endl;
        cout<<"2) Append"<<endl;
        cout<<"3) Delete first"<<endl;
        cout<<"4) Delete Last"<<endl;
        cout<<"5) Insert At"<<endl;
        cout<<"6) Delete At"<<endl;
        cout<<"7) Display"<<endl;
        cout<<"8) Reverse Display"<<endl;
        cout<<"9) Quit"<<endl;
        cout<<"Enter your Choice: "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"**************Prepend***************"<<endl;
            cout<<"Enter the data: "<<endl;
            cin>>data;
            l.prepend(data);
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 2:
            cout<<"**************Append***************"<<endl;
            cout<<"Enter the data: "<<endl;
            cin>>data;
            l.append(data);
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 3:
            cout<<"**************Delete First***************"<<endl;
            l.DeleteFirst();
            cout<<"Deleted successfully "<<endl;
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 4:
            cout<<"**************Delete Last***************"<<endl;
            l.DeleteLast();
            cout<<"Deleted successfully "<<endl;
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 5:
            cout<<"**************Insert At***************"<<endl;
            cout<<"The position is: ";
            cin>>pos;
            cout<<"The data is: ";
            cin>>data;
            l.InsertAt(pos,data);
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 6:
            cout<<"**************Delete At***************"<<endl;
            cout<<"The position is: ";
            cin>>pos;
            l.DeleteAt(pos);
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 7:
            cout<<"The list is: "<<endl;
            l.Display();
            break;
        case 8:
            cout<<"The Reversed list is: "<<endl;
            l.RevDisplay();
            break;
        case 9:
            cout<<"**************Exit***************"<<endl;
            exit(0);  
        default:
            cout<<"Enter the correct choice"<<endl;
        }     
    }while(choice != 9);
    return 0;
}