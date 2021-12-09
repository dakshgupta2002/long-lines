#include<bits/stdc++.h> 
using namespace std;



//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    
    bool isPresent(TreeNode* current, TreeNode* child){
        
        if (current == NULL) return false;
        
        if (current == child)return true; 
        
        return (isPresent(current->left, child) || 
                isPresent(current->right, child));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        if (root == NULL) return root; 
        
        if (isPresent(root->left, p) && isPresent(root->left, q)){
            return lowestCommonAncestor(root->left,p ,q);
        }else if(isPresent(root->right, p) && isPresent(root->right, q)){
            return  lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
        
    }
        
};
//optimised solution
//search for p and q in both left and right
//whichever comes first, return 
//if both found that means both in different subtree 
class Solution {
public:
     
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        if (root == NULL) return root; 
        if (root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p ,q);
        TreeNode *right = lowestCommonAncestor(root->right, p , q);
        
        
        
        if (left&&right){
            return root;
        }
        
        return left!=NULL?left:right;
    }
        
};