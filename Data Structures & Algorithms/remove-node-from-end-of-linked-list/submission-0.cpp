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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int length=0;
        ListNode* curr=head;
        //Steps1. Find the length of list
        while(curr!=NULL){
            length++;
            curr=curr->next;
        }
        //Steps2. Use temp node to simplify the delete 
        ListNode* temp=new ListNode(0);
        temp->next=head;
        //Steps3. Move the poniter to the target node Nth from the last target=(length-n+1)
        ListNode* prev=temp;
        for(int i=1;i<(length-n+1);i++){
            prev=prev->next;
        }
        //Steps4.Unlink the target Node and free the memory and repair the list
        ListNode* target=prev->next;
        prev->next=target->next;
        delete target;

        ListNode* newhead=temp->next;
        delete temp;
        return newhead;
    }
};
