#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void add(string &temp, char a){
        int i=0;
        while (true){
            if (temp[i]>a){
                temp.insert(i, 1, a);
                return;
            }else if (i==temp.length()){
                temp+=a; return;
            }
            i++;
        }
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        int len = s1.length();
        //cout << len << endl;
        sort(s1.begin(), s1.end());
        // s1 = acd, len =3 
        int i=0, j=len-1;

        string temp = "";
        for (int k=i; k<j; k++)temp += s2[k];
        sort(temp.begin(), temp.end());
        
        
        while (j < s2.length()){
            add(temp, s2[j]);            
            //cout << temp << endl;

            if (s1==temp) return true; 

            int ptr;
            for (ptr = 0; ptr<temp.length(); ptr++) if (temp[ptr] == s2[i]) break;
            temp.erase(ptr, 1);
            i++; j++;
        }

        return false;
    }
};