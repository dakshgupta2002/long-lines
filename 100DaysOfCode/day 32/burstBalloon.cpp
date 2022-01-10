#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int burst(vector<int> nums, int coins, map<vector<int>, int> &dp){
        if (nums.size()==1) return nums[0];         

        if (dp[nums]!=0) return dp[nums];

        //find min balloon to burst        
        int min=1000, index=-1;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]<min){
                min = nums[i];
                index=i;
            }
        }

        vector<int> balloons;        
        for (int j=0; j<nums.size(); j++){
            if (j!=min) balloons.push_back(nums[j]);
        }

        //burst this balloon 
        //add nums[i-1]*[i]*[i+1] and call for the next balloon        
        int thisOne=nums[index];
        if (index-1 >= 0) thisOne*=nums[index-1];
        if (index+1 < nums.size()) thisOne *= nums[index+1];

        thisOne += burst(balloons, coins, dp);

        return dp[nums] = thisOne;
    }
    int maxCoins(vector<int>& nums) {

        map<vector<int>, int> dp;
        return burst(nums, 0, dp);
    }
};