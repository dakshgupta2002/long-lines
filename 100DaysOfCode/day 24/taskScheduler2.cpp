#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> required(numCourses); 
        
        for (int i=0; i<prerequisites.size(); i++){
            required[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> order;
        vector<bool> done(numCourses, 0);
        while (true){
            if (order.size() == numCourses) return order; 

            int found=-1;

            for(int i=0; i<numCourses; i++){
                if (required[i].empty() && !done[i]){
                    found = i;
                    break; 
                }
            }

            if (found == -1){
                return {};
            }

            order.push_back(found);
            done[found]=1;
            //erase required from all other lists

            for(int i=0; i<numCourses; i++){
                required[i].remove(found);
            }
        }
    }
};