// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<iostream>
#include<vector>
using namespace std;

bool isBadVersion(int n){
    return false;
}


class Solution {
public:
    int firstBadVersion(int n) {
        int lo=1, hi=n; 
        int ans; 
        while (lo<=hi){
            int mid = (lo + (hi-lo)/2); 
            if (isBadVersion(mid)){
                ans = mid; 
                hi = mid-1; 
            }else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
};