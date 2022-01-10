#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int choices(vector<int> &nums, int index, vector<int> &dp){
        if (index >= nums.size()) return 0; 
        
        if (dp[index] != -1) return dp[index];        
        return dp[index] = max(nums[index]+choices(nums, index+2, dp), choices(nums, index+1, dp));      
        
        
    }
    
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        
        return  choices(nums, 0, dp);
    }
};