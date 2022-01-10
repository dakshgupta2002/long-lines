#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>> &grid, vector<vector<int>> &visited, int R, int C){
        if (R<0 || R>=grid.size())return 0; 
        if (C <0 || C>=grid[R].size()) return 0; 
        if (grid[R][C]==0 || visited[R][C]) return 0; 

        visited[R][C]=1;
        return 1 + maxArea(grid, visited, R+1, C) +  maxArea(grid, visited, R-1, C) +  maxArea(grid, visited, R, C+1)+  maxArea(grid, visited, R, C-1);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0; 

        vector<vector<int>> visited; 
        for (int i=0; i<grid.size(); i++){
            vector<int> v1; 
            for (int j=0; j<grid[i].size(); j++) v1.push_back(0);
            
            visited.push_back(v1);
        }


        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j]==1 && !visited[i][j]){
                    area = max(area, maxArea(grid, visited, i, j));
                }
            }
        }

        return area;
    }
};