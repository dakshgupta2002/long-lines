#include<bits/stdc++.h>
using namespace std;


//select first place 

class Solution {
public:
    int fac(int n){
        if (n==1 || n==0) return 1; 

        return n*fac(n-1);
    }       
    
    string getPermutation(int n, int k) {
    
        set<char> pq; 
        for (int i=1; i<=n; i++) pq.insert(i+'0');
        
        string ans="";

        for (int i=1; i<=n && k>1; i++){    
            
            int pos = (k-1)/fac(n-i);
            k -= pos*fac(n-i);             
            
            
            set<char> :: iterator it1 = pq.begin();
            while (pos--) it1++;
            ans += *it1;
            pq.erase(it1);           
            
            
            //cout << k << " "<< pos << " " << n-i  << " " << ans << endl;
        }
        
        
        while (!pq.empty()){
            ans += *pq.begin();
            pq.erase(*pq.begin());
        }

        return ans;
    }
};