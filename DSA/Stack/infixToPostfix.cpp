#include<iostream>
#include<string>

#define MAX_SIZE 1001
using namespace std;

class Stack{   
    private:
        int top; 
        char arr[MAX_SIZE];      //array to store

    public:
    //constructor
        Stack(){    
            top=-1;     //for empty stack
        };

    int empty(){
        if (top==-1) return 1;
        return 0;
    };

    void push(char c){
        if (top==MAX_SIZE-1){
            cout << "Stack overflow \n"; return;
        }
        arr[++top] = c;
        return;
    };
    void pop(){
        if(this->empty()){
            cout << "Stack underflow" << endl; return;
        }
        top--; return;
        
    };
    
    char peek(){
        if(this->empty()){
            return '_';}

        return arr[top]; 
    };
};


int precedence(char operation){ //precedence function
    if (operation=='^'){
        return 3;
    }else if (operation=='*' || operation=='/'){
        return 2;
    }else if (operation=='+' || operation=='-'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    Stack operationStack;
    string s; cin>>s;    //input
    string postfix=""; //output 
   
    for(int i=0; i<s.length(); i++){

 
        if (s[i] == '('){    //no matter what push the ( opening bracket 
            operationStack.push(s[i]);
        }else if(s[i]==')'){  //empty till the last bracket opening
            while(operationStack.peek() != '('){
                postfix+=operationStack.peek();
                operationStack.pop();
            }                
            operationStack.pop();

        }else if (precedence(s[i])==0){ //if it is an operand
            postfix+=s[i];

        }else{
            if (operationStack.empty() || (precedence(s[i]) > precedence(operationStack.peek())) ){   //if stack is empty or precedence is greater: push
                operationStack.push(s[i]);
            }else if (precedence(s[i]) == precedence(operationStack.peek()) &&
                    s[i]=='^'){  //if precedence is same it is ^: push
                operationStack.push(s[i]);
            }else{ //else pop till predence becomes strictly greater 
                
                while (!operationStack.empty() && operationStack.peek()!='(' &&
                    (precedence(s[i]) <= precedence(operationStack.peek()))){
                        postfix+=operationStack.peek();
                        operationStack.pop();
                }
                operationStack.push(s[i]);
            }
        }
    }
    while (!operationStack.empty()){  //empty the stack once string is over
        postfix+=operationStack.peek(); operationStack.pop();
    }
    cout << postfix;
}