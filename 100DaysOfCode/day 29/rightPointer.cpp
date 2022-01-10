#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;        
        if (root->left == NULL) return root; 
        
        //initially root next is null so do nothing
        if (root->next != NULL){
            root->right->next = root->next->left;
        }

        //ignite the connection of next 
        root->left->next = root->right;
        //at this point my next is set, so for next node
        //his children will connect then will his neighbour
        connect(root->left); 
        connect(root->right);
        
        return root;
    }   
};