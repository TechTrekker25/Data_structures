#include <iostream>
using namespace std;

class Queue_arr{
    private:
    int front;
    int rear;
    int *Queue;
    int size;
    int Numberofelements;
    public:
    Queue_arr(int size){
        this-> size= size;
        front = rear = -1;
        Queue = new int[size];
        Numberofelements = 0;
    }
    void enque(int data){
        if(Numberofelements == size){
            resize();
        }
        if(front == -1 && rear == -1 ){
            front=rear=0;
        }else{
            rear = (rear +1)%size;
        }
        Queue[rear] = data;
        Numberofelements++; 
    }
    void deque(){
        cout<<Queue[front]<<endl;
        if(Numberofelements<=0){
            cout<<"No elements to deque"<<endl;
        }else if(front==rear){
            front = rear = -1;
        }else{
            front = (front +1)%size;
        }
        Numberofelements--;
    }
    void resize(){
        int NewSize = size * 2;
        int *NewQueue = new int[NewSize];
        int j = front;
        for(int i=0;i<Numberofelements;i++){
            NewQueue[i] = Queue[j];
            j = (j+1)%size;
        }
        delete[] Queue;
        Queue = NewQueue;
        size = NewSize;
        front = 0;
        rear = Numberofelements-1;     
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