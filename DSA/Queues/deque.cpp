#include<iostream>
using namespace std;

class Deque{
    int top, bottom, size, deque_arr[];

    public:
        Deque(int blocks){
            size = blocks;
            top=-1; bottom=0; deque_arr[size];
        }

        int length(){
            if (top<bottom){
                return 0;
            }else{
                return top - bottom +1;
            }
        }

        void push_top(int x){
            if (this->length() == size){
                cout << "Dequeue overflow" << endl;
            }else{
                deque_arr[++top] = x;
            }
        }

        void push_bottom(int x){
            if (this->length() == size){
                cout << "Dequeue overflow" << endl;
            }else{
                deque_arr[--bottom] = x;
            }
        }

        bool empty(){
            if (this->length()==0){
                return true;
            }else return false;
        }

        void clear(){
            top=-1;
            bottom=0;
        }

        void remove_top(){
            if (this->length()>0){
                top--;
            }else{
                cout << "Deque is empty";
            }
        }

        void remove_bottom(){
            if (this->length()>0){
                bottom++;
            }else{
                cout << "Deque is empty";
            }
        }
};

int main(){
    Deque dq1(1);
    dq1.push_bottom(100);
    cout << dq1.length() <<endl;
    dq1.push_top(800);

    dq1.clear();
    cout << dq1.length() << endl;

    dq1.remove_bottom();

}

