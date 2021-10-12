#include<iostream>
using namespace std;

#define MAX_SIZE 5

struct Queue{                                               //|  | 3 | 4 | 5 | 6 | 7 | 8 |  |  |
                                                            //    front ------------- rear
    int rear, front;
    int arr[];

    Queue(){
        arr[MAX_SIZE]; rear=-1; front=-1;
    };



    bool empty(){
        if (front == -1 && rear == -1){  //"this" is a pointer that points towards called queue
            return true;
        }
        return false;
    }

    void enqueue(int x){
        if (rear==MAX_SIZE-1){
            cout << "Queue overflow" << endl; 
            return;           
        }
        
        arr[++rear]=x;  //put the data after incrementing rear

        if (front==-1) {
            front++;
        };  //if front is at -1, i.e. first element is inserted
    }

    void dequeue(){
        if (this->empty()){ 
            cout << "Queue is empty" << endl;
            return;
        }                                  
        

        if (front == rear){
            front = -1; rear = -1; //since now the queue is empty, reset the values
            return;
        }

        front++;
        
    }

    int peek(){
        if (this->empty()){
            cout << "Queue is empty"; return -1;
        }
        return arr[front];
    }

    void display(){
        if (this->empty()){
            cout << "Queue is empty" << endl; return;
        }
        for (int iterator=front; iterator<=rear; iterator++){
            cout << arr[iterator] << " ";
        }

        cout << endl;
    }
};

int main(){

    
    Queue q1; 
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
    return 0;
}