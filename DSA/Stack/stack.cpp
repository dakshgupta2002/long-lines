#include<iostream>
#define MAX_SIZE 5
using namespace std;

class Stack{   
    private:
        int top; 
        int arr[MAX_SIZE];      //array to store

    public:
    //constructor
        Stack(){    
            top=-1;     //for empty stack
        };

    int empty(){
        if (top==-1) return 1;
        return 0;
    };

    void push(int c){
        if (top==MAX_SIZE-1){
            cout << "Stack overflow \n"; return;
        }
        arr[++top] = c;
        
    };
    void pop(){
        if(this->empty()){
            cout << "Stack underflow" << endl; return; }
        top--;         
    };    
    int peek(){
        if(this->empty()){
            return -1;}
        return arr[top]; 
    };

    void display(){
        if (this->empty()){
            cout << "No elements to display."; return;
        }

        for (int itr = 0; itr<=top; itr++){
            cout << arr[itr] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s1;

    cout << "Stack empty: " << s1.empty()<< endl;//stack is empty
    s1.pop(); //underflow 

    for (int i=0; i<5; i++){
        s1.push(i);
    } //stack is full now 

    cout << "The complete stack now is: ";  s1.display(); 


    cout << "Top element: " << s1.peek() << endl;

    //try adding another element
    s1.push(6); //overflow


}

