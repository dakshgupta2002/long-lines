
#include<bits/stdc++.h>
using namespace std;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum(TreeNode* root){
        if (root==NULL) return 0; 
        
        return root->val + sum(root->right) + sum(root->left);
    }
    
    int findTilt(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right==NULL)){
            return 0; 
        }    
        
        return abs(sum(root->right) - sum(root->left)) + 
                findTilt(root->right) + findTilt(root->left);

    }
};