#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {


        int lo=0, hi=0; 
        string ans="";

        while (lo<title.length() && hi<title.length()){
          

            while (isalpha(title[hi]) && hi<title.length()) hi++;
            hi--;

            string temp = "", temp1=""; 
            for (int i=lo; i<=hi; i++) temp += tolower(title[i]);

            if (temp.size() > 2){
                //make first char larger 
                for (int i=0; i<temp.length(); i++){
                    if (i==0){
                        temp1 += toupper(temp[i]);
                    }else{
                        temp1 += temp[i];
                    }
                }
                ans += temp1; ans += " ";
            }else{
                //no need to make first char
                ans += temp; ans += " ";
            }
            //move to next word
            lo = hi+2; hi+=2;
        }
        
        ans.erase(ans.length()-1, 1);
        return ans;
    }
};