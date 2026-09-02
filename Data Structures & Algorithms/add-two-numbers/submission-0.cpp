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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* additionnode=new ListNode(0);
        ListNode* temp=additionnode;
        int carry=0;
        while(l1!= NULL || l2!=NULL || carry!=0 ){
            int sum=carry;
            //Steps1. add the int sum+=l1.data and sum+=l2.data
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            //Steps2. check the remainder(for carry=sum%10) then store in spearte node 
            carry=sum/10;
            int digit=sum%10;
           //Steps3. create the new node and advance the tail pointer
           temp->next=new ListNode(digit);
           temp=temp->next;
        }
        ListNode* result=additionnode->next;
        return result;
    }
};
