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
        int maxdiameter=0;
        calculatediameter(root,maxdiameter);

        return maxdiameter;
    }
    static int calculatediameter(TreeNode* root, int& maxdiameter){
        /*Height of empty binary tree*/
        if(!root)
        return 0;
        /*Path passing through this node*/
        int lefth=calculatediameter(root->left,maxdiameter);
        int righth=calculatediameter(root->right,maxdiameter);

        maxdiameter=max(maxdiameter, lefth+righth);
        /*Return height of current node to its parent*/
        return 1+max(lefth,righth);
    }
};
