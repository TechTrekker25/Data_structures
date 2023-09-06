#include <iostream>
using namespace std;

class BinaryHeap{
    private:
    int *heap;
    int heapSize;
    int Size;

    int getParent(int index){
        return (index-1)/2;
    }
    int getLeftchild(int index){
        return 2*index + 1;
    }
    int getRightchild(int index){
        return 2*index + 2;
    }
    bool HasLeft(int index){
        return getLeftchild(index)<heapSize;
    }
    bool HasRight(int index){
        return getRightchild(index)<heapSize;
    }
    void swap(int parent, int child){
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
    }
    void Minup(int index){
        if(index != 0){
            int parent = getParent(index);
            if(heap[index] < heap[parent]){
                swap(parent,index);
                Minup(parent);
            }
        }
    }
     void Maxup(int index){
        if(index != 0){
            int parent = getParent(index);
            if(heap[index] > heap[parent]){
                swap(parent,index);
                Maxup(parent);
            }
        }
    }
    void MinDown(int index){
        int parents = getParent(index);
        int RightChild = getRightchild(index);
        int LeftChild = getLeftchild(index);
        int min = index;
        if(HasLeft(index) && heap[LeftChild]<heap[min]){
            min = LeftChild;
        }
        if(HasRight(index) && heap[RightChild]<heap[min]){
            min = RightChild;
        }
        if(index != min){
            swap(index,min);
            MinDown(min);
        }   
    }

    void MaxDown(int index){
        int parents = getParent(index);
        int LeftChild = getLeftchild(index);
        int RightChild = getRightchild(index);
        int max = index;
        if(HasLeft(index) && heap[LeftChild]>heap[max]){
            max = LeftChild;
        }
        if(HasRight(index) && heap[RightChild] > heap[max]){
            max = RightChild;
        }
        if(max != index){
            swap(index,max);
            MaxDown(max);
        }
    }

    public:
    BinaryHeap(int size){
        heap = new int[size];
        Size = size;
        heapSize = 0;
    }
    int removeMin(){
        if(heapSize==0){
            cout<<"tree is empty"<<endl;
            return -1;
        }else{
            int root = heap[0];
            heap[0] = heap[heapSize-1];
            heapSize--;
            if(heapSize > 1){
                MinDown(0);
            }
            return root;
        }
    }
    int removeMax(){
        if(heapSize==0){
            cout<<"tree is empty"<<endl;
            return -1;
        }else{
            int root = heap[0];
            heap[0]=heap[heapSize-1];
            heapSize--;
            if(heapSize > 1){
                MaxDown(0);
            }
            return root;
        }
    }
    void insertMin(int data){
        if(heapSize==Size){
            cout<<"Array is full"<<endl;
        }else{
           heapSize++;
           heap[heapSize-1] = data;
           Minup(heapSize-1);
        }
    }
    void insertMax(int data){
        if(heapSize==Size){
            cout<<"Array is full"<<endl;
        }else{
           heapSize++;
           heap[heapSize-1] = data;
           Maxup(heapSize-1);
        }
    }
    ~BinaryHeap(){
       delete[] heap;
    }
};

int main() {
    BinaryHeap Bin(7);
    int first;
    int second;
    int data;

    cout << "[Max-1/Min-2]: ";
    cin >> first;

    if (first == 1) {
        do {
            cout << "**********Binary Max***********" << endl;
            cout << "1) Insertion" << endl;
            cout << "2) Deletion" << endl;
            cout << "3) Exit" << endl;
            cout << "Enter your choice: ";
            cin >> second;
            
            switch (second) {
                case 1:
                    cout << "Enter the data: ";
                    cin >> data;
                    Bin.insertMax(data);
                    break;
                case 2:
                    cout << "*******Deleted Successfully******" << endl;
                    cout << Bin.removeMax() << endl;
                    break;
                case 3:
                    cout << "*******Exit Successfully******" << endl;
                    exit(0);
                    break;
                default:
                    cout << "Invalid Option" << endl;
            }
        } while (second != 3);
    } else if (first == 2) {
        do {
            cout << "**********Binary Min***********" << endl;
            cout << "1) Insertion" << endl;
            cout << "2) Deletion" << endl;
            cout << "3) Exit" << endl;
            cout << "Enter your choice: ";
            cin >> second;

            switch (second) {
                case 1:
                    cout << "Enter the data: ";
                    cin >> data;
                    Bin.insertMin(data);
                    break;
                case 2:
                    cout << "*******Deleted Successfully******" << endl;
                    cout << Bin.removeMin() << endl;
                    break;
                case 3:
                    cout << "*******Exit Successfully******" << endl;
                    exit(0);
                    break;
                default:
                    cout << "Invalid Option" << endl;
            }
        } while (second != 3);
    } else {
        cout << "Enter valid option" << endl;
    }

    return 0;
}
