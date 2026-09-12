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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        return {};

        vector<vector<int>>result;
        queue<TreeNode*>qt;

        qt.push(root);

        while(!qt.empty()){
            int level=qt.size();
            vector<int>levelres;
            for(int i=0;i<level;i++){
                TreeNode* curr=qt.front();
                qt.pop();
                levelres.push_back(curr->val);

                if(curr->left)
                qt.push(curr->left);

                if(curr->right)
                qt.push(curr->right);
            }
            result.push_back(levelres);
        }
    return result;
    }
};
