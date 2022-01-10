#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closest(vector<vector<int>>& mat, int x, int y, int radius){
        
        int R = mat.size()-1;
        int C = mat[0].size()-1;
        //on top y = y+radius
        //on bottom  y=y-radius
        for (int move = -radius; move<=radius; move++){
            //check for out of bounds
            if (((x+move>=0 && x+move<=R) && (y+radius>=0 && y+radius<=C) && mat[x+move][y+radius] == 0)
                || ( (x+move>=0 && x+move<=R) &&  (y-radius>=0 && y-radius<=C) && mat[x+move][y-radius]==0)
                ) return true;
        }

        //on left x=x-radius
        //on right x=x+radius
        for (int move = -radius; move<=radius; move++){
             if ((x+radius>=0 && x+radius<=R) && (y+radius>=0 && y+radius<=C) && (mat[x+radius][y+move] == 0)
                || ((x-radius>=0 && x-radius<=R) &&  (y+move>=0 && y+move<=C) && mat[x-radius][y+move]==0  ) 
                ) return true;
        }

        //not found on this circle
        return false;

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat[i].size(); j++){

                if (mat[i][j]==1){
                    //find closest zero
                    for (int r=1; r<max(mat.size(), mat[0].size()); r++){
                        if (closest(mat, i, j, r)){
                            mat[i][j] = r;
                            break;
                        }
                    }
                    
                }
            }
        }

        return mat;
    }
};