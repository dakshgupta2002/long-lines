#include<iostream>
using namespace std;

class Queue{
    private:
        int front, rear, MAX_CAPACITY; 
        int arr[];

    public:
    Queue(int size){
        MAX_CAPACITY=size; 
        int* arr= new int[size]; //dynamic memory allocation in heap
        front=-1; rear=-1;
    }

    void enqueue(int x){
        if (front==-1 && rear==-1){  //initial state always empty, push the element
            arr[++rear]=x; front++; return;
        }
        if ((front==0 && rear==MAX_CAPACITY-1) || rear==front-1){ //check if queue is full
            cout << "Queue Overflow\n"; return;
        }
        if (rear==MAX_CAPACITY-1){    //circulating the rear to arr[0] since front>0
            rear=0;   
        }else{rear++;}

        arr[rear]=x; 

    }

    void dequeue(){
        if (front==-1){          //no element to remove
            cout << "Queue Underflow\n"; return; 
        }

        if (front==rear){
            front=rear=-1; return;  //reset the queue to initial state
        }
        if (front==MAX_CAPACITY-1){   //circulating to start
            front=0; return; 
        }
        front++;

    }

    int peek(){
        if (front==-1){
            cout << "Queue is empty\n"; return -1; 
        }

        return arr[front];
    }

    void display(){
        if (front==-1){cout << "Queue is empty\n"; return; }

        int i=front; 
        while (true){
            if (i==rear){
                cout << arr[i] << endl; return;
            } 
            cout << arr[i] << ' ';
            if (i==MAX_CAPACITY-1){
                i=0;
            }else{
                i++;
            }
        }
    }
};

int main(){

    cout << "Size of the Queue? "; 
    int size; cin>>size;

    Queue q1(size);

    cout << "THE MENU FOR QUEUE COMMANDS(x is the integer): " << endl << 
    "1) To insert element to rear: 1 x" << endl << 
    "2) To remove from front: 2" << endl<< 
    "3) To print the queue: 3" << endl <<
    "4) To print the front element: 4" << endl <<
    "5) To exit: 5" << endl;


    while (true){
        int command;
        cin >> command;

        if (command == 5) break; 

        if(command == 4){
            cout << q1.peek() << endl;
        }else if (command == 3){
            q1.display();
        }else if (command == 2){
            q1.dequeue();
        }else{
            int num; cin>>num;
            q1.enqueue(num);
        }
    }
}