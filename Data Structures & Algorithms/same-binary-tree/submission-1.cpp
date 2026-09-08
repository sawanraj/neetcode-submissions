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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>>nodepair;
        nodepair.push({p,q});

        while(!nodepair.empty()){
            auto[node1,node2]=nodepair.front();
            nodepair.pop();
            /*Both nodes are null, at this postion it is valid*/
            if(!node1 && !node2)
            continue;
            /*Any of them is null or their value is not matching return false, is not same tree*/
            if(!node1 || !node2 || node1->val !=node2->val)
            return false;

            /*push the left and right children of it, to check in future iteration*/
            nodepair.push({node1->left,node2->left});
            nodepair.push({node1->right,node2->right});
        }

        return true;
    }
};
