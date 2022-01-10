#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> used = vector<int>(25, 0); 
    
    bool checkPowersOfThree(int n) {
        if (n==0) return true;
        
        //find max power which is less than n 
        int power=20; 
        while(true){
            if (pow(3, power) <= n && !used[power]){
                used[power]=1;
                return checkPowersOfThree(n - pow(3, power));
            } 
            power--;
            
            if (power<0) return false;
        }
        
        
    }
};