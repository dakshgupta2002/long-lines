#include<bits/stdc++.h>
using namespace std;

//( song1 % 60 + song2 % 60 ) % 60 = 0
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //we will map remainder to number of such songs 
        
        unordered_map<int, int> m1; 
        int ans=0;
        for (int i=0; i<time.size(); i++){
            int rem = time[i]%60; 
            ans += m1[(60-rem)%60];
            
            m1[rem]++;
            
        }
        
        return ans;
    }
};