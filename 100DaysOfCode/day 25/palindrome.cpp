#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long long int reverse=0; 
        
        int size=0; 
        long long int temp = x, y=x;
        while (temp){
            temp/=10; size++;
        }
        
        
        while(x){
            reverse += (x%10)*(pow(10, --size));
            x/=10;
        }
        
        return reverse==y;
    }
};