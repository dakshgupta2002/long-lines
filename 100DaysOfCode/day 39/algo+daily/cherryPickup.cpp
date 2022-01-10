#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCherry(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r, int c1, int c2)
    {
        if (r == grid.size()) return 0;
        if (c1<0 || c1>=grid[0].size() || c2<0 || c2>=grid[0].size()) return -1000000;

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        //calculate the max for this position
        int ans = 0;
        //we have 9 choices here
        if (r < grid.size()-1){
            for (int i = -1; i <= 1; i++){
                for (int j = -1; j <= 1; j++){

                    int move = maxCherry(grid, dp, r+1, c1+i, c2+j);
                    ans = max(ans, move);
                }
            }
        }
        int fin = c1==c2? ans + grid[r][c1] : ans + grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2]=fin;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {

        vector<vector<vector<int>>> dp;

        for (int i=0; i<100; i++){
            vector<vector<int>> row;
            for (int j=0; j<100; j++){
                vector<int> col(100, -1);
                row.push_back(col);
            }
            dp.push_back(row);
        }

        int last = grid[0].size() - 1;
        

        return maxCherry(grid, dp, 0, 0, last);
    }
};