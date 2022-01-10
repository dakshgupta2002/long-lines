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
    ListNode* join(ListNode* oddHead, ListNode* &oddTail, ListNode* evenHead, ListNode* &evenTail){
        
        if (evenTail == NULL){
            oddTail->next = evenHead; 
            return oddHead; 
            
        }
        
        if (evenTail->next == NULL){
            oddTail->next = evenHead; 
            return oddHead;
        }
        
        
        oddTail->next = oddTail->next->next; 
        oddTail = oddTail->next; 
        
        if (oddTail->next == NULL){           
            
            evenTail->next = NULL;             
            oddTail->next = evenHead; 
            cout << "base" << oddHead->val << evenTail->val << endl;
            return oddHead;
        }
        evenTail->next =oddTail->next; 
        evenTail = evenTail->next; 
        
        return join(oddHead, oddTail, evenHead, evenTail);
        
        
    }
        
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next==NULL) return head; 
        ListNode * oddTail = head, *evenTail = head->next;
        return join(head, oddTail, head->next, evenTail);
    }
};