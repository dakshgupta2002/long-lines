#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;
         //xor with 1111...11111
        
        //finding highest power of 2 in num
        int i=31;
        for (; i>=0; i--){
            if (pow(2, i) <= n) break; 
        }
        
        
        //making decimal representation of 111....1111
        int xorOp=0; 
        for (int j=i; j>=0; j--) xorOp += pow(2, j);
        
        
        return n^xorOp;
    }
};
