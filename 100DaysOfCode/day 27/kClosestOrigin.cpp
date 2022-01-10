#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq; 
        vector<vector<int>> v1;

        for (int i=0; i<points.size(); i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];

            pq.push({dist, i}); 

            if (pq.size()>k) pq.pop();
        }   

        while (pq.size()){
            v1.push_back(points[pq.top().second]);
        }

        return v1;
    }
};