#include<bits/stdc++.h>
using namespace std;

// for a permutation of s1 to be in s2
// all chars of s1 should be in a window of s2
// keep a track of map of all characters
// and keep track of matched chars, at each stage

class Solution {
public:

    int match(map<char, int> m1, map<char, int> m2){
        int x=0;
        for (char t = 'a'; t<='z'; t++){
            if (m1[t] == m2[t]) x++;
        }

        return x;
    }
    
    
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        map<char, int> m1, m2; 
        for (int i=0; i<s1.length(); i++) m1[s1[i]]++; 

        int i=0, j=s1.length()-1; 
        for (int k=i; k<j; k++) m2[s2[k]]++;

        int matched = match(m1, m2);

        while (j<s2.length()){
            m2[s2[j]]++; 
            if (m1[s2[j]]==m2[s2[j]]) matched++;
            else if (m2[s2[j]]-1 == m1[s2[j]]) matched--;

            if (matched == 26) return true;

            m2[s2[i]]--;
            if (m1[s2[i]]==m2[s2[i]]) matched++;
            else if (m2[s2[i]]+1 == m1[s2[i]]) matched--;

            i++; j++;
        } 
        

        return false;
    }
};