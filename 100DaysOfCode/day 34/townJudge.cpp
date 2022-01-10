#include<bits/stdc++.h>
using namespace std;

//its a dag
//check for indegree n-1 and outdegree 0 

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> outdeg, indeg;

        for (int i=0; i<trust.size(); i++){
            outdeg[trust[i][0]]++;
            indeg[trust[i][1]]++;
        } 

        for (int i=1; i<=n; i++){
            if (indeg[i]==n-1 && outdeg[i]==0) return i;
        }

        return -1;

    }
};