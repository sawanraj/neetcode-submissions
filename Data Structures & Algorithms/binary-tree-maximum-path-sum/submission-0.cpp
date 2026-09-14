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
int msum;
    int maxsum(TreeNode* root){
        if(!root)
        return 0;

        int leftsum=max(0,maxsum(root->left));
        int rightsum=max(0,maxsum(root->right));

        msum=max(msum,leftsum+rightsum+root->val);

        return root->val+max(leftsum,rightsum);

    }
    int maxPathSum(TreeNode* root) {
        msum=INT_MIN;
        maxsum(root);
        return msum;
    }
};
