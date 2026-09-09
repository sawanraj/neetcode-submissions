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
    bool isBalanced(TreeNode* root) {
        return heightoftree(root) != -1;
    }
    static int heightoftree(TreeNode* root){
        if(!root)
        return 0;

        int leftheight=heightoftree(root->left);
        if(leftheight == -1)
            return -1;

        int rightheight=heightoftree(root->right);
        if(rightheight == -1)
            return -1;
        if(abs(leftheight-rightheight) > 1)
            return -1;

        return max(leftheight,rightheight)+1;
    }
};
