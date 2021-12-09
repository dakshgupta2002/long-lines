
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

class Solution {
public:
    
    bool bs(TreeNode* root, long long int min, long long int max){
        if (root == NULL){
            return true; 
        }
        
        return (root->val > min && root->val < max && 
           bs(root->left, min, root->val) && 
               bs(root->right, root->val, max));
    }
    
    bool isValidBST(TreeNode* root) {
        
        return bs(root, -10000000000000000, 10000000000000000);
        
    }
};