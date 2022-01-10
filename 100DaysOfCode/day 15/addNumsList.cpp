#include<bits/stdc++.h>
using namespace std; 
//https://leetcode.com/problems/add-two-numbers/

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

    void insert(ListNode* &head, ListNode* &tail, int val){       
        
        if (head==NULL){
            tail = new ListNode(val); 
            head = tail; 
            return;
        }
        
        tail->next = new ListNode(val);
        tail = tail->next; 
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head= NULL, *tail=NULL; 
        
        int carry=0; 
        while (l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry; 
            
            insert(head, tail, sum%10); 
            carry = sum/10; 
            
            l1 = l1->next; l2 = l2->next;
        }
        
        while (l1 != NULL){
            int sum = l1->val + carry; 
            
            insert(head, tail, sum%10); 
            carry = sum/10; 
            
            l1=l1->next;
        }
        
        while (l2 != NULL){
            int sum = l2->val + carry; 
            
            insert(head, tail, sum%10); 
            carry = sum/10; 
            
            l2=l2->next;
        }
        if (carry != 0){
            insert(head, tail, carry);
        }
        return head;
        
        
    }
};