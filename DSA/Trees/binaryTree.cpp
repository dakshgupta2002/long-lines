#include <iostream>
//#include<algorithm>
#define ent cout <<endl;
using namespace std;

struct binaryNode
{
    int val; //properties
    binaryNode *left = NULL;
    binaryNode *right = NULL;

    binaryNode(int x)
    { //constructor
        val = x;
    }
};

binaryNode* head = NULL;

struct Queue{                                               //|  | 3 | 4 | 5 | 6 | 7 | 8 |  |  |
                                                            //    front ------------- rear
    int rear, front;
    binaryNode* arr[];

    Queue(){
        arr[10]; rear=-1; front=-1;
    };



    bool empty(){
        if (front == -1 && rear == -1){  //"this" is a pointer that points towards called queue
            return true;
        }
        return false;
    }

    void enqueue(binaryNode* x){
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

    binaryNode* peek(){
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


//bst operations 

void Insertion(int data)
{

    if (head == NULL)
    {
        head = new binaryNode(data);
        return;
    }

    binaryNode* temp = head;
    binaryNode* inserted = new binaryNode(data);

    while (temp != NULL){
        //cout << temp->val << endl;
        if (data < temp->val){
            if (temp->left == NULL){
                temp ->left = inserted;
                return;
            }
            temp = temp->left;
        }else{
            if (temp -> right == NULL){
                temp -> right = inserted;
                return;
            }
            temp = temp->right;
        }
    }
}

bool Search(int data)
{
    if (head == NULL){
        return 0;
    }
    binaryNode* temp = head; 
    while (temp != NULL){
        if (temp->val == data){
            return 1;
        }else if(data < temp->val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    return 0;
}


// int maxVal(binaryNode* parent)
// {
//     if (parent->right == NULL){
//         return parent->val;
//     }

//     return maxVal(parent->right);
// }

// int sumOfTree(binaryNode* parent){
//     if (parent == NULL){
//         return 0;
//     }

//     return parent->val + sumOfTree(parent->left) + sumOfTree(parent->right);
// }

// int height(binaryNode* parent){
//     if (parent==NULL){
//         return -1;
//     }

//     return max(height(parent->left)+1, height(parent->right)+1);
// }

void bfs(binaryNode* parent){
    if (parent==NULL){
        return;
    }

    Queue children;
    children.enqueue(parent);

    while (!children.empty()){
        cout << (children.peek())->val <<" ";
        
        if (children.peek()->left != NULL) children.enqueue(children.peek()->left);
        if (children.peek()->right != NULL) children.enqueue(children.peek()->right);
        children.dequeue();
    }
    return;
}

void preOrder(binaryNode* parent){
    
    if(parent == NULL){
        return;
    }

    cout << parent->val << " ";
    preOrder(parent->left);
    preOrder(parent->right);
}

void inOrder(binaryNode* parent){
    if (parent== NULL){
        return;
    }

    inOrder(parent->left);
    cout << parent->val << " ";
    inOrder(parent->right);
}

void postOrder(binaryNode* parent){
    if (parent==NULL){
        return;
    }
    postOrder(parent->left);
    postOrder(parent->right);
    cout << parent->val << " ";
     
}



binaryNode* minVal(binaryNode* parent){
    

    if (parent->left == NULL){
        return parent;
    }

    return minVal(parent->left);


}


binaryNode* Deletion(binaryNode* parent, int key){
    if (parent==NULL){
        return parent;
    }

    if ( key < parent->val) 
    {
        parent->left = Deletion(parent->left, key);
    }else if ( key > parent->val)
    {
        parent->right = Deletion(parent->right, key);
    }else{
        if (parent->left == NULL && parent->right == NULL){
            delete parent;
            return NULL;
        }else if (parent->left == NULL){
            binaryNode* temp = parent->right; 
            delete parent;
            return temp;
        }else if (parent->right == NULL){
            binaryNode* temp = parent->left; 
            delete parent;
            return temp;
        }else{
            binaryNode* temp = minVal(parent->right);
            parent->val = temp->val;
            parent->right = Deletion(parent->right, parent->val);

        }
        return parent;
    }


}

int main()
{
        int command;

    cout << "For Insertion: 1 x\nFor Searching: 2 x\nFor traversals: Inorder ->3, PostOrder->4, PreOrder->5\nDeletion: 6 x \nTo exit: 7\n";
    while (true){
        cin>>command;

        if (command==1){
            int num; cin>>num;
            Insertion(num); cout << "Inserted\n";
        }else if (command==2){
            int num; cin>>num;
            cout << Search(num) <<endl;
        }else if (command==3){
            inOrder(head); cout << endl;
        }else if (command==4){
            postOrder(head); cout << endl;
        }else if (command==5){
            preOrder(head); cout << endl;
        }else if (command==6){
            int num; cin>>num;
            Deletion(head, num);
        }else{
            break;
        }
    }
}

