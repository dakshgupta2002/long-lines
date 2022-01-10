#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> inorder(numCourses, 0);
        vector<vector<int>> freed(numCourses);

        for (auto &o: prerequisites){
            if (o[0]==o[1]) return false;
            freed[o[1]].push_back(o[0]);
            inorder[o[0]]++;
        }
        vector<int> order;      

        for (int i=0; i<numCourses; i++){
            if (inorder[i] == 0){
                order.push_back(i);
            }
        }
        

        for (int y=0; y<order.size(); y++){
            int e = order[y];
            cout << order.size() << endl;
            for (auto &f : freed[e]){
                if (--inorder[f] == 0) order.push_back(f);
           
            }
        }

        return order.size() == numCourses;


    }
};