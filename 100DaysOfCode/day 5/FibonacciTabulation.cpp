//https://leetcode.com/problems/fibonacci-number/submissions/


class Solution {
public:
    int fib(int n) {
        
        if (n==0) return 0;
        
        int curr=1, prev=0; 
        
        for(int i=2; i<=n; i++){
            int temp = curr; 
            curr = curr + prev; 
            prev = temp; 
        }
        
        return curr;
    }
};