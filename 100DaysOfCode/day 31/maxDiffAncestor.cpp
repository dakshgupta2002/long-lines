#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//i only want maximum difference so maintain only 
// maximum and minimum values from the ancestor 

class Solution {
public:
    
    int subtreeDiff(TreeNode* parent, int maxR, int minR, int diff){
        //at each step a new ancestor is added 
        if (parent==NULL) return diff;
        
        //update answer if i find a larger one, and still keep looking for better one
        diff = max(  { diff, abs(maxR - parent->val), abs(minR - parent->val) }  );

        //update if this ancestor has least or greatest values
        if (parent->val > maxR) maxR = parent->val;
        if (parent->val < minR) minR = parent->val; 
        
        //call for its right and left subtree with updated max-min values 

        return max(subtreeDiff(parent->left, maxR, minR, diff) ,                                                                      subtreeDiff(parent->right, maxR, minR, diff));
    }
    int maxAncestorDiff(TreeNode* root) {
        int minR = root->val; 
        int maxR = root->val;
        return max(subtreeDiff(root->left, maxR, minR, 0), subtreeDiff(root->right, maxR, minR, 0));
    }
};