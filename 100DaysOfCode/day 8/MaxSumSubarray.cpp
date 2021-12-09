//https://leetcode.com/problems/maximum-subarray/

//we have base case of picking the last element only
//then for each index from n-1 to 0,,,, 
//we see if what is the best elements to pick

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[nums.size()-1]; 
        
        for (int i=nums.size()-2; i>=0; i--){
            nums[i] = max(nums[i], nums[i]+nums[i+1]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};

//Kadanes Algorithm