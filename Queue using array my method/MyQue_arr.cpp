#include <iostream>
using namespace std;

class Queue_arr{
    private:
    int front;
    int rear;
    int *Queue;
    int numofelement;
    int size;
    public:
    Queue_arr(int size){
        this->size = size;
        Queue = new int[size];
        front = rear = -1;
        size = 0;
        numofelement = 0;
    }
    void Enque(int data){
        if(numofelement == size){
            resize();
        }
        if(front == -1 && rear==-1){
            front = rear = 0;
        }else{
            rear++;
        }
        Queue[rear] = data;
        numofelement++;
    }
    void deque(){
        if(front>numofelement-1){
            cout<<"Queue is empty"<<endl;
        }else{
            cout<< Queue[front]<<endl;
            front++;
        }
    }
    void resize(){
     int NewSize = size*2;
     int *NewQueue = new int(NewSize);
     for(int i = 0; i<numofelement;i++){
        NewQueue[i] = Queue[i];
     }
     delete[] Queue;
     Queue = NewQueue;
     front = 0;
     rear = numofelement-1;
     size = NewSize;
    }
    ~Queue_arr(){
        delete[] Queue;
    }
};

int main(){
    Queue_arr Q(3);
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
            Q.Enque(data);
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