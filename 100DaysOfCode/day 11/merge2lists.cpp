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
    
    void insert(ListNode* &head, ListNode* &tail, int value){
        if (head == NULL){
            tail = new ListNode(value); 
            head = tail; 
        }else{
            tail->next= new ListNode(value);
            tail=tail->next;           
        }
        
 
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL, *tail=NULL; 
        
        while(list1 != NULL && list2 != NULL){
            if (list1->val < list2->val){
                insert(head, tail, list1->val);
                list1 = list1->next;
            }else{
                insert(head, tail, list2->val);
                list2 = list2->next;
            }
        }
        
        while (list1 != NULL){
            insert(head, tail, list1->val);
            list1 = list1->next;
        }
        while(list2 != NULL){
            insert(head, tail, list2->val);
            list2 = list2->next;
        }
        
        return head;
    }
};