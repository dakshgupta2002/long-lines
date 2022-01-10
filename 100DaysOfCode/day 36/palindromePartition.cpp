#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pal(string s){
        for (int i=0; i<s.length(); i++){
            if (s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }
    void combination(string &s, vector<vector<string>> &solution, int index, int last, vector<string> current){
        string temp="";
        for(int i=index; i<=last; i++){
            temp += s[i];
        }

        if (pal(temp)){
            current.push_back(temp);
            
            if (last == s.length()-1){
                solution.push_back(current);
                return; 
            }
             
            index = last+1;
            for (int i=index; i<s.length(); i++){
                combination(s, solution, index, i, current);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> solution; 

        for (int i=0; i<s.length(); i++) combination(s, solution, 0, i, {});
        return solution;
    }
};