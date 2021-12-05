
//https://leetcode.com/problems/odd-even-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* implement(ListNode* head, ListNode*odd, ListNode* evenHead, ListNode*                                                                                         evenTail){
        
        if(odd==NULL) return head;
        
        if(odd->next == NULL){
            odd->next = evenHead;
            evenTail->next = NULL;
            return head;
            
        }  
        
        if (odd->next->next == NULL){
            evenTail->next = odd->next;
            evenTail->next->next = NULL;
            odd->next = evenHead;
            return head;
        }
        
        if(odd->next->next->next == NULL){
            odd->next = odd->next->next; 
            
            return implement(head, odd->next, evenHead, evenTail);
        }
        
        
      
        odd->next = odd->next->next;        
        evenTail->next = evenTail->next->next; 
        
        return implement(head, odd->next, evenHead, evenTail->next);
        
    }
    
    
    ListNode* oddEvenList(ListNode* head) {
    
        if (head == NULL ||head->next == NULL){
            return head;
        }
        return implement(head, head, head->next, head->next);
        
        
        
        
    }
};