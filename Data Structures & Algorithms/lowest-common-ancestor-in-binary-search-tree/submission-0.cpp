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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root==p || root==q)
            return root;

        TreeNode* leftt=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightt=lowestCommonAncestor(root->right,p,q);

        if(leftt && rightt)
            return root;

        return leftt?leftt:rightt;
    }
};
