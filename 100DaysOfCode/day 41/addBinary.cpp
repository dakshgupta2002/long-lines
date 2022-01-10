#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string addBinary(string a, string b) {
        int i=a.length()-1, j=b.length()-1; 
        bool carry=0; 
        string ans="";


        while (i>=0 || j>=0){
            if (i>=0 && j>=0){
                if (carry){
                    if (a[i]=='1' && b[j]=='1'){
                        ans.insert(0, 1, '1');
                    }else if (a[i]=='0' && b[j]=='0'){
                        ans.insert(0, 1, '1');
                        carry=0;
                    }else{
                        ans.insert(0,1,'0');
                    }
                }else{
                    if (a[i]=='1' && b[j]=='1'){
                        ans.insert(0, 1, '0');
                        carry=1;
                    }else if (a[i]=='0' && b[j]=='0'){
                        ans.insert(0, 1, '0');
                    }else{
                        ans.insert(0, 1,'1');
                    }
                }
            }else if (i<0){
                if (carry){
                    if (b[j]=='1'){
                        ans.insert(0, 1, '0');
                    }else{
                        ans.insert(0, 1, '1');
                        carry=0;
                    }
                }else{
                    if (b[j]=='1'){
                        ans.insert(0, 1, '1'); carry=0;
                    }else{
                        ans.insert(0, 1, '0');
                    }
                }
            }else if (j<0){
                if (carry){
                    if (a[i]=='1'){
                        ans.insert(0, 1, '0');
                    }else{
                        ans.insert(0, 1, '1');
                        carry=0;
                    }
                }else{
                    if (a[i]=='1'){
                        ans.insert(0, 1, '1'); carry=0;
                    }else{
                        ans.insert(0, 1, '0');
                    }
                }
            }
            i--; j--;
        }

        if (carry) ans.insert(0, 1, '1');

        return ans;
    }
};