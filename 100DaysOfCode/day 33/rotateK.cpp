#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //if k = size, then after k times you'll recieve the same array 
        k = k%nums.size();
        
        // 1 2 3 4 5 6 7 
        reverse(nums.end()-k, nums.end());
        // 1 2 3 4 7 6 5 
        reverse(nums.begin(), nums.end());
        // 5 6 7 4 3 2 1
        reverse(nums.begin()+k+1, nums.end());
        // 5 6 7 1 2 3 4    
    }
};