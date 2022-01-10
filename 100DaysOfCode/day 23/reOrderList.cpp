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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return; 
        
        stack<ListNode*> s1; 
        
        ListNode* temp = head; 
        int size = 0; 
        while(temp){
            size++;
            temp = temp->next;
        }
        
        temp = head;
        int i=1;
        for (; i<=size/2+size%2; i++){
            temp = temp->next;
        }

     
        for(; i<=size; i++){
            s1.push(temp);
            temp = temp->next; 
        }
        
        temp = head; 
        
        while (!s1.empty()){
            
            ListNode* temp2 = temp->next;
            temp->next = s1.top();
            temp->next->next = temp2; 
            

            temp = temp2; 
            s1.pop();
            
            
        }
        
        temp = head;
        for (int i=1; i<size; i++){
            temp = temp->next; 
        }
        
        temp->next = NULL;
    }
};
