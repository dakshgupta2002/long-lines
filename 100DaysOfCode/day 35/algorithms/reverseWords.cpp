#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(string &s, int start, int end){
        while (start< end){
            int temp = s[start];
            s[start]= s[end];
            s[end]=temp;

            start++; temp--;
        }
    } 
    string reverseWords(string s) {
        int start=0, end=0; 
        while (start< s.length()){
            while (s[end] != ' ') end++; 
            //found a word
            //reverse this word
            reverse(s, start, end);
            start = end +1; end++;
        }

    }
};