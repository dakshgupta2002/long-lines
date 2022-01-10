#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged; 

        for (int i=0; i<intervals.size(); i++){
            int start=intervals[i][0], end=intervals[i][1]; 

            while (i+1<intervals.size() && end >= intervals[i+1][0]){
                end = max(end, intervals[i+1][1]);

                i++;
            }

            merged.push_back({start, end});
        }

        return merged;
    }
};