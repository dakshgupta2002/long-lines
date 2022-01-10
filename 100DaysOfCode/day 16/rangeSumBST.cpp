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
//if value is in range, add the value 
//and return for both subtrees

//but if value is less than range, then the left subtree will always be smaller
//and if larger than range, then right subtree always greater
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) return 0; 
        
        if (root->val < low)  return rangeSumBST(root->right, low, high);
            
        else if (root->val > high) return rangeSumBST(root->left, low, high);
            
        else if (root->val >=low && root->val <= high) 
            return root->val+rangeSumBST(root->left, low, high)+rangeSumBST(root->right, low, high);
        
        return 0;
        
    }
};