#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {

        int looking=0, x=0, y=0;

        for (int i=0; i<instructions.length(); i++){
            if (instructions[i]=='G'){
                if (looking == 0) y++;
                else if (looking == 1) x--;                    
                else if (looking == 2) y--;
                else if (looking == 3) x++;
                
            }else if (instructions[i]=='L') looking = (looking+1)%4;
            else if (instructions[i]=='R') {
                if (looking != 0) looking --;
                else looking = 3;
            }
            
        }

        //net direction change
        if (looking == 0 && (x!=0 || y!=0)) return false;
        return true;
    }
};