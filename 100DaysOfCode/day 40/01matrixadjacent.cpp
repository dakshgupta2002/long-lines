#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closest(vector<vector<int>>& mat, vector<vector<int>> &visited, int x, int y){
        if (x>=0 && x<mat.size() && y>=0 && y<mat[x].size()){
            if (mat[x][y]==0) return 0;
            visited[x][y]=1;
            return 1+ min( { closest(mat, visited, x+1, y), closest(mat, visited, x-1, y), closest(mat, visited, x, y+1), closest(mat, visited, x, y-1)});
        }
        return 100000;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat[i].size(); j++){

                if (mat[i][j]==1){
                    //find closest zero
                    vector<vector<int>> visited(mat.size()-1, vector<int>(grid[0].size(), 0));
                    mat[i][j] = closest(mat, visited, i, j);
                    
                }
            }
        }

        return mat;
    }
};