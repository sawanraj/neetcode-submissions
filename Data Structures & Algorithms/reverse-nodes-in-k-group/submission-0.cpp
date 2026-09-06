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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int count=0;
       //Check if there are at least k nodes 
        while(count<k){
            if(!curr)return head;
            curr=curr->next;
            count++;
        }
        //Reverse the current group of K nodes
        curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        for(int i=0;i<k;i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //Next is still not null Recursively process the rest and link the results
        if(next!= NULL){
            head->next=reverseKGroup(next,k);
        }
    return prev;
    }
};
