#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0; 
        unordered_map<char, int> appear;

        int i=0, j=0; 
        int currLen = 0;

        while (j<s.length()){
            if (appear[s[j]] == 0){
                appear[s[j]]++;

                currLen++;
                j++;
            }else{
                currLen--;

                appear[s[i]]--;
                i++;
            }

            longest = max(longest, currLen);
        }

        return longest;

    }
};