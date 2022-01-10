#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K==2 || K==5) return -1; 
        
        for (int r = 0, N = 1; N <= K; ++N)
            //we check 11....11 for every length from 1 to K
            //each number will give remainde of 0,1,2,,,(K-1)
            //after this the remainders starts repeating hence we can stop 
            
            if ((r = (r*10 + 1) % K) == 0)
            //to prevent overflow 
            //we can take modulo at each step 
            //the part that is currently divisible will be removed
            //the remainder keeps adding to other remainders 
                return N;
        return -1;
    }
};