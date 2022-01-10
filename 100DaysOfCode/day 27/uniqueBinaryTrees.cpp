#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int combo(int nodes, vector<int> &dp){ 
        
        if (dp[nodes] != -1) return dp[nodes];
        
        int combinations=0; 
        for (int i=1; i<=nodes; i++){
            //parent is i 
            if (i==1 || i==nodes) combinations += combo(nodes-1, dp); 
            else combinations += combo(nodes-i, dp)*combo(i-1, dp);
        }
        
        return dp[nodes] = combinations;
        
    }
    int numTrees(int n) {
        if (n==1) return 1; 
        if (n==2 ) return 2;
        vector<int> dp(n+1, -1);
        dp[0]=1;
        dp[1]=1; 
        return combo(n, dp);
    
    }
};