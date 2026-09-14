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
    int maxPathSum(TreeNode* root) {
        int msum=INT_MIN;
        vector<TreeNode*> nodes;
        queue<TreeNode*>qs;
        unordered_map<TreeNode*, int>branchmax; //collect branch max

        qs.push(root);
        while(!qs.empty()){
            TreeNode* curr=qs.front();
            qs.pop();

            nodes.push_back(curr);//put inside Vector each node
            if(curr->left)
                qs.push(curr->left);
            if(curr->right)
                qs.push(curr->right);
        }
        //Process vector nodes in reverse BFS order
        for(int i=nodes.size()-1;i>=0;i--){
            TreeNode* curr=nodes[i];

            int leftsum=curr->left?max(0,branchmax[curr->left]):0;
            int rightsum=curr->right?max(0,branchmax[curr->right]):0;

            msum=max(msum,leftsum+rightsum+curr->val);
            branchmax[curr]=curr->val+max(leftsum,rightsum);
        }
        return msum;
    }
};
