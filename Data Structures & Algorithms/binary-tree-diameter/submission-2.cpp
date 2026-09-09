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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;

        int maxd=0;

        unordered_map<TreeNode*,int>heights;
        stack<TreeNode*>travstk;
        stack<TreeNode*>postostk;
        travstk.push(root);

        while(!travstk.empty()){
            TreeNode* curr=travstk.top();
            travstk.pop();
            postostk.push(curr);

            if(curr->left)
            travstk.push(curr->left);

            if(curr->right)
            travstk.push(curr->right);
        }
        
        while(!postostk.empty()){
            TreeNode* curr=postostk.top();
            postostk.pop();
            
            int leftheight=curr->left?heights[curr->left]:0;
            int rightheight=curr->right?heights[curr->right]:0;

            maxd=max(maxd,leftheight+rightheight);
            heights[curr]=1+max(leftheight, rightheight);
        }

        return maxd;
    }
};
