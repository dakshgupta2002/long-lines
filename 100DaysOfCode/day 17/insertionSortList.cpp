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
    ListNode* insert(ListNode* sortHead, int val){
        ListNode* add = new ListNode(val);
        
        if (sortHead == NULL){
            sortHead = add;
            return sortHead; 
        }  
        
        if (val < sortHead->val){
            add->next = sortHead;
            sortHead = add; 
            return sortHead;
        }
        
        ListNode* temp = sortHead;
        while(temp != NULL){
            if (temp->next == NULL){
                temp->next = add;
                return sortHead; 
            }else if (val < temp->next->val){
                add->next = temp->next;
                temp->next = add;
                return sortHead;
     
            }
            temp = temp->next;
        }
        return sortHead;
    }
    
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortHead = NULL;
        
        while(head != NULL){
            sortHead = insert(sortHead, head->val);
            head = head->next; 
        }
        
        return sortHead;
    }
};