#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left = right = NULL;
    }
};

class BST{
    private:
    Node *root;
    void insert_Node(int data,Node *&current){
        Node *n = new Node(data);
        if(current == NULL){
            current = new Node(data);
        }else if(data==current->data){
            cout<<"data already exist"<<endl;
        }
        else if(data < current->data){
            if(current->left==NULL){
                current->left = new Node(data);
            }else{
                insert_Node(data,current->left);
            }
        }else if(data> current->data){
            if(current->right==NULL){
                current->right = new Node(data);
            }else{
                insert_Node(data,current->right);
            }
        }
    }
    void delete_node(int data,Node *&current){
        if(current == NULL){
            cout<<"The tree is empty"<<endl;
        }else if(data < current->data){
            delete_node(data,current->left);
        }else if(data > current->data){
            delete_node(data,current->right);
        }else{
            if(current->left==NULL && current->right == NULL){
                 delete current;
                 current = NULL;
            } 
            else if(current->left == NULL){
                Node *temp = current;
                current = current->right;
                delete temp;
            }else if(current->right == NULL){
                Node *temp = current;
                current = current->left;
                delete temp;
            }
            else{
                Node *temp = findMin(current->right);
                current->data = temp->data;
                delete_node(temp->data,current->right);
            }
        }
    }
    void Search_Node(int data, Node* current){
        if(data==current->data){
            cout<<data<<" is found in the tree"<<endl;
        }else if(data<current->data){
            Search_Node(data,current->left);
        }else if(data>current->data){
            Search_Node(data,current->right);
        }else{
            cout<<data<<" is not found in the tree"<<endl;
        }
    }
    Node* findMin(Node* current){
        while(current->left != NULL){
            current = current->left;
        }
        return current;
    }
    public:
    BST(){
        root = NULL;
    }
    void insert(int data){
        insert_Node(data,root);
    }
    void remove(int data){
        delete_node(data,root);
    }
    void search(int data){
        Search_Node(data,root);
    }
}; 

int main(){
    BST B;
    int choice;
    int data;
    do{
        cout<<"***********Binary Search Tree*******************"<<endl;
        cout<<"1) Insert"<<endl;
        cout<<"2) Deletion"<<endl;
        cout<<"3) Search"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"********Insertion********"<<endl;
            cout<<"Enter the data to insert: ";
            cin>>data;
            B.insert(data);
            break;
        case 2:
            cout<<"*********Deletion*********"<<endl;
            cout<<"Enter the data to delete: ";
            cin>>data;
            B.remove(data);
            break;
        case 3:
            cout<<"*********Search*********"<<endl;
            cout<<"Enter the data to search: ";
            cin>>data;
            B.search(data);
            break;
        case 4:
            cout<<"**********Exit*********"<<endl;
            exit(0);
        default:
            cout<<"Enter valid option"<<endl;
        }

    }while(choice != 4);
    

}