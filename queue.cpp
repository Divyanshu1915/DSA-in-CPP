#include<iostream>
#include<queue>
#define Capacity 10

using namespace std;

class Queue{
    private:
    int queue[Capacity];
    int front;
    int size;
    public:
    Queue(){
        front=0;
        size=0;

    }
void enqueue(int element){
    if(size==Capacity){
        cout<<"Queue is full:<<endl";

    }
    int rear=(front+size)%Capacity;
    queue[rear]=element;
    size++;
}
//Here size represent the no. of element currently present in the queue 
//capacity represent the total capacity of the queue

int dequeue(){
    if(size==0){
        cout<<"Queue is empty"<<endl;
        return -1;

    }
    int element=queue[front];
    front=(front+1)%Capacity;
    size--;
    return element;

}
int peek(){
    if(size==0){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
        return queue[front];
}
int isempty(){
    cout<<"Isempty"<<boolalpha<<(size==0)<<endl;
    return size==0;
    
}
int getsize(){
    cout<<"Size of queue"<<size<<endl;
    return size;
}
void printQueue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << (char)queue[(front + i) % Capacity] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');

    q.printQueue();

    cout << "Dequeue: " << (char)q.dequeue() << endl;
    cout << "Peek: " << (char)q.peek() << endl;
    cout << "isEmpty: " << boolalpha << q.isempty() << endl;
    cout << "Size: " << q.getsize() << endl;

    return 0;
}

