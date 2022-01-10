#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        
        int minDiff=100000000; 
        
        for (int i=0; i<arr.size()-1; i++){
            minDiff = min(minDiff, abs(arr[i]-arr[i+1]));            
        }
        
        
        vector<vector<int>> sol; 
        
        for (int i=0; i<arr.size()-1; i++){
            if (abs(arr[i]-arr[i+1]) == minDiff){
                sol.push_back( {arr[i], arr[i+1]});
            }
        }
        
        return sol;
    }
};