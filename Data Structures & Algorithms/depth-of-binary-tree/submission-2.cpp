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
    int maxDepth(TreeNode* root) {
        if(!root)
           return 0;
    /*BFS using iterative */
    queue<TreeNode*>qn;
    //int rightdepth=0;
    //int leftdepth=0;
    int depth=0;
    qn.push(root);
    while(!qn.empty()){
        int level=qn.size();

         //Process all children at the current level
        for(int i=0;i<level;i++){
            TreeNode* curr=qn.front();
            qn.pop();
            if(curr->left!=NULL){
                qn.push(curr->left);
            }
            if(curr->right!= NULL){
                qn.push(curr->right);
            }
        } 
        depth++;
    }
    return depth;
    //return 1+max(leftdepth,rightdepth);  
    }
};
