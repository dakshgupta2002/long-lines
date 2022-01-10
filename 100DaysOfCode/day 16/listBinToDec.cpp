#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int size=0;
        ListNode* temp = head; 
        while (temp != NULL){
            size++; 
            temp = temp->next;
        }
        
        temp = head; 
        int decimal = 0; 
        
        while(temp != NULL){
            decimal += (temp->val)*(pow(2,size-1));
            size--;
            temp = temp->next;
        }
        
        return decimal;
    }
};