#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<char>> alpha = { {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, 
                                      {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    
    vector<string> combo(string s, string digits, int index, vector<string> &sol){
        if (index >= digits.length()){
            sol.push_back(s);
            return sol;
        }
        
        for (int i=0; i< alpha[digits[index] - '0'].size(); i++){
            combo(s+alpha[digits[index] -'0'][i], digits, index+1, sol);
        }
        
        return sol;
        
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        if (digits == ""){
            vector<string> v1;
            return v1;
        }
        vector<string> sol;
        
        for (int i=0; i<alpha[digits[0]-'0'].size(); i++ ){
            string s= "";
            s+= alpha[digits[0]-'0'][i]; 
            
            //add all possible char ahead 
            combo(s, digits, 1, sol);
            
        }
        
        return sol; 
    }
};