#include<bits/stdc++.h>
using namespace std;

//nlogn binary search
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         for (int i=0; i<numbers.size()-1;; i++){

//             //binary search for number 
//             int lo=numbers[i+1], hi=numbers[numbers.size()-1];
//             while (lo<=hi){
//                 int mid = lo + (hi-lo)/2; 

//                 if (numbers[mid]+numbers[i] < target) lo = mid+1;
//                 else if (numbers[mid]+numbers[i] > target) hi = mid-1;
//                 else return {i+1, mid+1};
//             }
//         }
//     }
// };

//n two pointer 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi=numbers.size()-1; 
        while (numbers[lo]+numbers[hi] != target){
            if (numbers[lo]+numbers[hi] < target) lo++;
            else hi--;
        }
        return {lo+1, hi+1};

    }
};