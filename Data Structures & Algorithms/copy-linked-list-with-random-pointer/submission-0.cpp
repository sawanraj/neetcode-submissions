/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return nullptr;

        //Steps1. Hash map to original to clone node
        unordered_map<Node*,Node*>oldtonew;

        //Steps2. First pass:create a new node for each original Node
        Node* curr=head;
        while(curr){
            oldtonew[curr]=new Node(curr->val);
            curr=curr->next;
        }
        //Stpes3. Connect next and random pointer
        curr=head;
        while(curr){
            oldtonew[curr]->next=oldtonew[curr->next];
            oldtonew[curr]->random=oldtonew[curr->random];
            curr=curr->next;
        }
        return oldtonew[head];
    }
};
