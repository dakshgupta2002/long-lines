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
    ListNode* swapNodes(ListNode* head, int k) {
        //find size
        ListNode* temp = head; 
        int size=0;
        while(temp){
            size++; 
            temp = temp->next;
        }

        int last = size-k+1; 

        if (last < k) {
            int temp = k; 
            k = last;
            last = temp;

        }
        int lastVal;
        //find first value reach last and store in first 
        temp = head;
        for (int i=1; i<last; i++){
            if (i==k) lastVal=temp->val;

            temp = temp->next; 
        }
        int firstVal = temp->val;
        temp->val = lastVal; 
        
        //swap value of kth start
        temp = head;
        for (int i=1; i<k; i++){
            temp = temp->next;
        }
        temp ->val = firstVal;
        return head;
    }
};