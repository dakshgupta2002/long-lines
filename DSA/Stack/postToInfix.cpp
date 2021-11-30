#include<iostream>
using namespace std;

class Stack{
    int top,cap; string arr[];

    public:
        Stack(int size){        
            cap = size;
            string arr[cap];
            top=-1;
        };

    void push(string x){
        if (top==cap-1){
            cout << "Stack overflow" << endl;
        }else{
            arr[++top] = x;
        }
    };
    void pop(){
        if(top==-1){
            cout << "Stack underflow" << endl;
        }else{
            top--;
        }
    };
    bool empty(){
        return top==-1;
    };
    int peek(){
        if(top==-1){cout<<"Empty"; return 0;}
        else{
            return arr[top]; 
        }
    }

};

int main(){
    string s; cin>>s;

    Stack st(s.length());

    for (int i=0; i<s.length(); i++){
        if (s[i] == '+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            string first_operand=st.peek(); st.pop();
            string second_operand=st.peek(); st.pop();

            string ans; //calculate first s[i] second;
            if (s[i] == '+'){
                ans = second_operand + '+' + first_operand;
            }else if (s[i] == '-'){
                ans = second_operand + '-' + first_operand;
            }else if (s[i] == '*'){
                ans = second_operand + '*' + first_operand;
            }else{
                ans = second_operand + '/' + first_operand;
            }
            st.push(ans);
        }else{
            st.push(s[i]);
        }
    }

    cout << st.peek();
}