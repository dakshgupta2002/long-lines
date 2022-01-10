#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> spread(vector<vector<int>>& image, vector<vector<int>> &visited, int sr, int sc, int oldColour, int newColor) {
        if (sr <0 || sr>=image.size()) return image; 
        if (sc < 0 || sc >= image[sr].size()) return image; 

        if (image[sr][sc] != oldColour) return image;
        if (visited[sr][sc]) return image; 

        image[sr][sc] = newColor;
        visited[sr][sc]=1;
        
        spread(image, visited, sr+1, sc, oldColour, newColor);
        spread(image, visited, sr-1, sc, oldColour, newColor);
        spread(image, visited, sr, sc+1, oldColour, newColor);
        spread(image, visited, sr, sc-1, oldColour, newColor);

        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visited;
        for (int i=0; i<image.size(); i++){
            vector<int> v1; 
            for (int j=0; j<image[i].size(); j++) v1.push_back(0);
            
            visited.push_back(v1);
        }
        return spread(image, visited, sr, sc, image[sr][sc], newColor);
    }
};


// 2 1 2
// 1 1 1