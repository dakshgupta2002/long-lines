#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        string ss="";
        for(int i=0; i<s.length(); i++){
            if (s[i]!=' ') ss+= s[i];
        } 
        s =ss;

        stack<long long int> sup; 

        char op='+';

        for(int i=0; i<s.length(); i++){
            long long int temp=0; 

            if (s[i] == '-') op='-';
            else if (s[i]=='*') op='*';
            else if (s[i]=='/') op = '/';
            else if (s[i]=='+') op = '+';

            else{
                 while(i<s.length() && isdigit(s[i])) {

                    temp = temp*10 +s[i]-'0';
                    i++;
                
                }
                if (i<s.length()) i--;
                
                if (op=='*'){
                    int calc = sup.top()*temp;
                    sup.pop();
                    sup.push(calc);
                }else if (op=='/'){
                    int calc = sup.top()/temp;
                    sup.pop();
                    sup.push(calc);
                }else if (op=='-'){
                    sup.push(-temp);
                }else sup.push(temp);
                
            }
                    

            
        }
        cout << sup.top() << endl;
        while (sup.size()!=1){
            long long int op1 = sup.top(); sup.pop();
            long long int op2 = sup.top(); sup.pop();
            sup.push(op1+op2);
        }
        
        return sup.top();

    }
};