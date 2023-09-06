#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Linked_list{
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    int Getsize(){
        return size;
    }
    Linked_list(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void prepend(int data){
        Node *n = new Node(data);
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            n->next = head;
            head = n;
        }
        size++;
    }
    void append(int data){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;        
        }
        size++;
    }
    void DeleteFirst(){
        if(size=0){
            cout<<"The list is empty";
        }else{
            Node *temp = head;
            head = temp->next;
            delete temp;
            size--;
        }
    }
    void DeleteLast(){
        if(size=0){
            cout<<"List is empty";
        }else if(head->next=NULL){
            DeleteFirst();
            size--;
        }else if (head->next != NULL){
            Node *curr = head;
            Node *prev;
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
        }
        tail = prev;
        tail->next=NULL;
        delete curr;
        size--;
        }
    }
    void InsertAt(int pos, int data){
        if(pos<1 || pos>size+1){
            cout<<"Enter valid position"<<endl;
        }else if(pos == 1){
            prepend(data);
        }else if(pos==size+1){
            append(data);
        }else{
            Node *n = new Node(data);
            Node *curr = head;
            Node *prev;
            for(int i=1;i<pos;i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = n;
            n->next = curr;
            size++;
        }
    }
    void DeleteAt(int pos){
        if(pos<1 || pos>size+1){
            cout<<"Enter valid position";
        }else if(pos==1){
            DeleteFirst();
        }else if(pos==size){
            DeleteLast();
        } else if(head->next != NULL){
            Node *curr = head;
            Node *prev;
            for(int i = 1;i<pos;i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }  
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    ~Linked_list(){
        Node *next ;
        while(head != NULL){
            next = head->next;
            delete head;
            head = next;
        }
    }
};

int main(){
    Linked_list l;
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
        cout<<"8) Quit"<<endl;
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
            l.display();
            break;
        case 2:
            cout<<"**************Append***************"<<endl;
            cout<<"Enter the data: "<<endl;
            cin>>data;
            l.append(data);
            cout<<"The list is: "<<endl;
            l.display();
            break;
        case 3:
            cout<<"**************Delete First***************"<<endl;
            l.DeleteFirst();
            cout<<"Deleted successfully "<<endl;
            cout<<"The list is: "<<endl;
            l.display();
            break;
        case 4:
            cout<<"**************Delete Last***************"<<endl;
            l.DeleteLast();
            cout<<"Deleted successfully "<<endl;
            cout<<"The list is: "<<endl;
            l.display();
            break;
        case 5:
            cout<<"**************Insert At***************"<<endl;
            cout<<"The position is: ";
            cin>>pos;
            cout<<"The data is: ";
            cin>>data;
            l.InsertAt(pos,data);
            cout<<"The list is: "<<endl;
            l.display();
            break;
        case 6:
            cout<<"**************Delete At***************"<<endl;
            cout<<"The position is: ";
            cin>>pos;
            l.DeleteAt(pos);
            cout<<"The list is: "<<endl;
            l.display();
            break;
        case 7:
            cout<<"The list is: "<<endl;
            l.display();
            break;
        case 8:
            cout<<"**************Exit***************"<<endl;
            exit(0);  
        default:
            cout<<"Enter the correct choice"<<endl;
        }     
    }while(choice != 8);
    return 0;
}