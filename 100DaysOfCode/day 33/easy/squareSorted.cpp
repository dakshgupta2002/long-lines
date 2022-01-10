#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]>=0){
                pos=i;
                break;
            } 
        } 
        int neg = pos-1;
        
        vector<int> square; 
        
        
        while (true){
            if (neg < 0 && pos>=nums.size()) break;
            
            if (neg < 0){
                square.push_back(nums[pos]*nums[pos]);
                pos++;
            }else if (pos>=nums.size()){
                square.push_back(nums[neg]*nums[neg]);
                neg--;
            }else{
                if (abs(nums[neg]) < nums[pos] ){
                    square.push_back(nums[neg]*nums[neg]);
                    neg--;
                }else{
                    square.push_back(nums[pos]*nums[pos]);
                    pos++;
                }
            }
        }
        
        return square;
    }
};