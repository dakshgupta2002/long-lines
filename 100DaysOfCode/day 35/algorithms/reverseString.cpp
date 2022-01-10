#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0, last= s.size()-1; 

        while (first< last){
            int temp = s[last];
            s[last] = s[first];
            s[first]=temp;

            last--; first++;
        }
    }
};