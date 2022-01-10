#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        string temp =  to_string(num);
        
        while (temp.length()>1){
            int ans = 0;
            for (int i=0; i<temp.length();i++){
                ans += temp[i]-'0';
            }
            
            temp = to_string(ans);
        }
        
        stringstream sol(temp);
        int aa; 
        sol >> aa;
        
        return aa;
    }
};