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
private:
    int random;
    int size=0;
    ListNode* temp;
public:
    Solution(ListNode* head) {
        random=0; 
        temp = head;

        while (head){
            size++; head= head->next; 
        }
    }
    
    int getRandom() {
        random = (random+1)%size;

        
        for (int i=1; i<random; i++){
            temp = temp->next;
        }

        return temp->val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main(){
    srand(time(0));
    cout << (float)rand();
}