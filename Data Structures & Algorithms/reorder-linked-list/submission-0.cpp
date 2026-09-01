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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;

        ListNode* slow=head;
        ListNode* fast=head;

        //steps1. find the middle node
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //Steps2. Reverse the second half of the list
        ListNode* secondhalf=reverseList(slow->next);
        slow->next=NULL;//Split the list into 2 halves
        //Steps3. Integrate 2 half 
        ListNode* firsthalf=head;
        while(secondhalf){
            ListNode* temp1=firsthalf->next;
            ListNode* temp2=secondhalf->next;

            firsthalf->next=secondhalf;
            secondhalf->next=temp1;

            firsthalf=temp1;
            secondhalf=temp2;
        }
    }
    static ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
