#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n); 
        for (int i=0; i<n; i++){
            if ( (i+1)%3 ==0) ans[i]+="Fizz";
            if ( (i+1)%5 == 0) ans[i]+= "Buzz";
            
            if (ans[i]=="") ans[i] += to_string(i+1);
        }
        
               
        return ans;
    }
};