#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;         
        int ans=nums.size(); 
        
        while (lo <= hi){
            int mid =  hi - (hi-lo)/2; 
            
            
            if (nums[mid] == target) return mid;             
            
            if (nums[mid]< target) lo = mid+1; 
            else{
                ans = mid; 
                hi=mid-1;
            }
        }
        return ans;
    }
};