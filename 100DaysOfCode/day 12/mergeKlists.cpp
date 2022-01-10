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
//compare all nodes one by one 
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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL , *tail = NULL;
        
        while (true){
            ListNode* minForThis = NULL; 
            int index; 
            
            for (int i=0; i<lists.size(); i++){
                if (lists[i] == NULL) continue; 
                
                if (minForThis == NULL){
                    minForThis = lists[i]; 
                    index = i; 
                } 
                else{
                    if (minForThis->val > lists[i]->val){
                        minForThis = lists[i];
                        index=i; 
                    }
                }
            }
            
            if (minForThis == NULL) break; 
            
            insert(head, tail, minForThis->val); 
            lists[index] = (lists[index])->next;
        }
        
        return head;
    }
};


//insert all nodes in a heap and then insert in head 
//iterating over all node O(N) -> and pushing in heap 
//heapify runs for logN max-> then pop all
//so NlogN