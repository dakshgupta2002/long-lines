#include<iostream>
using namespace std;


//nodes of binary tree defined
struct bstNode{ 
    int val; 
    bstNode* left;
    bstNode* right;

    bstNode(int value){
        val = value; left=right=NULL; 
    }       
};

bstNode* head=NULL;


//implementing custom queue
struct Queue{                                              
    
                                                             //|  | 3 | 4 | 5 | 6 | 7 | 8 |  |  |
                                                            //    front ------------- rear
    int rear, front;
    bstNode* arr[];

    Queue(){
        arr[10]; rear=-1; front=-1;
    };



    bool empty(){
        if (front == -1 && rear == -1){  //"this" is a pointer that points towards called queue
            return true;
        }
        return false;
    }

    void enqueue(bstNode* x){
        if (rear==9){
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

    bstNode* peek(){
        if (this->empty()){
             return NULL;
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
//gloval queue for storing tree second last and last level
Queue q1;

//Complete Binary tree Functions 
void Insertion(int value){
    //q1.display();
    if (q1.empty()){
        head = new bstNode(value);
        q1.enqueue(head);
        return;
    }
    if ((q1.peek())->left == NULL){
        q1.peek()->left = new bstNode(value);
        q1.enqueue( q1.peek()->left);
    }else if (q1.peek()->right ==NULL){        
        q1.peek()->right = new bstNode(value);
        q1.enqueue( q1.peek()->right);
        q1.dequeue();
    }

};
void preOrder(bstNode* parent){
    if (parent==NULL){
        return;
    }

    cout << parent->val << " ";
    preOrder(parent->left);
    preOrder(parent->right);
}

void inOrder(bstNode* parent){
    if (parent==NULL){
        return;
    }

    inOrder(parent->left);
    cout << parent->val << " ";
    inOrder(parent->right);
}
void postOrder(bstNode* parent){
    if (parent==NULL){
        return;
    }

    postOrder(parent->left);
    postOrder(parent->right);
    cout << parent->val << " ";
}

bool Search(bstNode* parent, int value){
    if (parent==NULL){
        return false;
    }
    if (parent->val == value){
        return true;
    }
    if ( Search(parent->left, value) ||  Search(parent->right, value)){
        return true;
    }
    return false;


}
int main(){

    int command;

    cout << "For Insertion: 1 x\nFor Searching: 2 x\nFor traversals: Inorder ->3, PostOrder->4, PreOrder->5 \nTo exit: 6\n";
    while (true){
        cin>>command;

        if (command==1){
            int num; cin>>num;
            Insertion(num); cout << "Inserted\n";
        }else if (command==2){
            int num; cin>>num;
            cout << Search(head, num) <<endl;
        }else if (command==3){
            inOrder(head); cout << endl;
        }else if (command==4){
            postOrder(head); cout << endl;
        }else if (command==5){
            preOrder(head); cout << endl;
        }else{
            break;
        }
    }

    
}
