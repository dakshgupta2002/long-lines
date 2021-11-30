#include<iostream>
using namespace std; 

struct Node{int data; Node* next;};
Node* first;

void Insert(int data, int index){
    Node* naya = new Node();
    naya->data=data;

    Node* temp = first;

    if (temp == NULL){
        if (index==1){ 
            naya->next =first; first = naya;         
            return;
        }        
        cout << "Index out of range\n"; return;

    }else{
        for (int i=1; i<index-1; i++){
            if (temp==NULL){
                cout << "Index out of range\n"; return;
            }
            temp = temp->next;
        }      
        naya->next = temp->next; 
        temp->next=naya;
    }
    
    
};

void Print(){
    Node* it2 = first; 
    while (it2!=NULL){
        cout << it2->data << " ";
        it2=it2->next;
    }
    cout << endl;
};

void Remove(int index){
    if (index==1){
        first = first->next; return;
    }else{
        Node* it2 = first; 
        for (int i=1; i<index-1; i++){
            if (it2 == NULL){
                cout << "Index out of range."; return;
            }
            it2 = it2->next;
        }
        if (it2->next == NULL)return;

        it2->next = it2->next->next;
    }
}

void Reverse(){
    Node* backward=NULL; Node* current=first; Node* forward;
    if (current->next == NULL)return; 

    while (current!=NULL){
        forward = current->next;
        
        current->next = backward;
        backward = current;
        current = forward;
    }

    first = backward;
}


int main(){
    first  = NULL;
    
    Insert(12,1);
    Insert(5,1);
    Insert(6, 3);
    Insert(7,4);    
   
    Print();

    Remove(3); Print();

    Reverse(); Print();
}

