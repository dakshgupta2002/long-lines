#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL && r2 == NULL) return NULL;

        TreeNode *r3 = new TreeNode( (r1==NULL?0:r1->val) + (r2==NULL?0 : r2->val) );
        r3->left = mergeTrees(r2==NULL?NULL:r2->left, r1==NULL?NULL:r1->left);
        r3->right = mergeTrees(r2==NULL?NULL:r2->right, r1==NULL?NULL:r1->right);


        return r3;
    }
};


//MY old solution
//same approach but just not used ternary operator
//and thought of using height for some reason
//if both nodes null, just return 
// and need to set left and right pointer at each step

/*
class Solution
{
public:
    int height(TreeNode *parent)
    {
        if (parent == NULL)
            return -1;

        return 1 + max(height(parent->left), height(parent->right));
    }

    int val(TreeNode *r1, TreeNode *r2)
    {
        int value = 0;
        if (r1 != NULL)
            value += r1->val;
        if (r2 != NULL)
            value += r2->val;

        return value;
    }

    TreeNode *merged(TreeNode *r1, TreeNode *r2, int h, int depth, TreeNode *r3)
    {
        if (depth > h)
            return r3;

        if (r1 == NULL && r2 == NULL)
            return r3;

        r3 = new TreeNode(val(r1, r2));

        if (r1 == NULL)
        {
            r3->left =merged(NULL, r2->left, h, depth+1, r3->left);
            r3->right =merged(NULL, r2->right, h, depth+1, r3->right);
        }
        else if (r2 == NULL)
        {
            r3->left =merged(r1->left, NULL, h, depth+1, r3->left);
            r3->right =merged(r1->right, NULL, h, depth+1, r3->right);
        }
        else
        {
            r3->left = merged(r1->left, r2->left, h, depth+1, r3->left);
            r3->right = merged(r1->right, r2->right, h, depth+1, r3->right);
        }

        return r3;
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        int h = max(height(root1), height(root2));
        TreeNode *root3 = NULL;
        return merged(root1, root2, h, 0, root3);
    }
};

*/