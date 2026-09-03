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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) //corner case empty vector
            return nullptr;
        int n=lists.size(); //size
        int interval=1; //inteval for each sorted list
        while(interval<n){
            for(int i=0;i<n-interval;i+=interval*2){
                //calling merge two sorted list concept only.
                lists[i]=mergetwolists(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
    return lists[0];
    }
    static ListNode* mergetwolists(ListNode* l1, ListNode* l2){
        ListNode temp(0);
        ListNode* curr=&temp;

        while(l1!= NULL && l2!=NULL){
            //Comparsion and linking to l1 and l2.
            if(l1->val <=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next=(l1!=NULL)?l1:l2;
        return temp.next;
    }
};
