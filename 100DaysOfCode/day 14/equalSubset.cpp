#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    
    bool subsets(vector<int> &nums, int currSum, int target, int i, vector<vector<int>> &dp){

        if (currSum == target) return true; 
        if (currSum > target || i == nums.size()) return false; 
        
        if (dp[i][currSum] != -1) return dp[i][currSum]; 
        
        return dp[i][currSum] = (subsets(nums, currSum, target, i+1, dp) || 
                                    subsets(nums, currSum+nums[i], target, i+1, dp));
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2 == 1) return false; 
        
        vector<vector<int>> dp; 
        vector<int> row(sum, -1); 
        
        for(int i=0; i<nums.size(); i++){
            dp.push_back(row);
        }
        
        return subsets(nums, 0, sum/2, 0, dp);
    }
};