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
    int goodNodes(TreeNode* root) {
        return findgoodone(root,root->val);;
    }
    int findgoodone(TreeNode* root, int maxsofar){
        if(!root)
        return 0;
        int gcount = (root->val >=maxsofar)?1:0;
        maxsofar =max(maxsofar,root->val);
        gcount+= findgoodone(root->left,maxsofar);
        gcount+= findgoodone(root->right,maxsofar);
        return gcount;
    }
};
