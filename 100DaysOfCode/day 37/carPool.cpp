#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        //find passengers at each distance in the trip
        int minStart = 1000; int maxDest=0; 
        
        for (int i=0; i<trips.size(); i++){
            minStart = min(minStart, trips[i][1]);
            maxDest = max(maxDest, trips[i][2]);
        }
        
        //at each point of our route 
        //check for passengers to add
        for (int i=minStart; i<=maxDest; i++){
            //add passengers from each route 
            int currPass=0; 
            for (int it = 0; it<trips.size(); it++){
                if ( i >= trips[it][1] && i<= trips[it][2]) currPass+= trips[it][0];
            }
            //cout << i << " " << currPass << endl;

            if (currPass >capacity) return false;
        }
        return true;
    }
};


//[[3,3,5],[4,5,6],[1,2,7],[3,2,8],[10,5,9],[2,5,9],[1,2,5]]
//19