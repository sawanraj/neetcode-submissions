/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root ==NULL)
           return NULL;

        queue<TreeNode*>qn;
        qn.push(root);
        /*Here we are going on each level swapping left to right and right to left and push all node first in queue then poping at each level(BFS-breadth first search)*/
        while(!qn.empty()){
            TreeNode* curr=qn.front();
            qn.pop();
            //Swap the left and right
            swap(curr->left,curr->right);
            //Push non-null children into the queue 
            if(curr->left!=NULL){
                qn.push(curr->left);
            }
            if(curr->right!= NULL){
                qn.push(curr->right);
            }
        }
    return root;
    }
};
