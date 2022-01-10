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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head; 

        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        //find the nth node from start
        n=size-n+1;
        //if first then remove
        if (n==1)return head->next;
        
        //reach to n-1 position
        temp=head;
        for (int i=1; i<n-1; i++){
            temp =temp->next;
        }
        //removal operation
        temp->next = temp->next->next;
        return head;
    }
};
