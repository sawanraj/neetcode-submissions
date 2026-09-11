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
    unordered_map<int,int>inmp;
    int pre_indx=0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_indx=0;
        inmp.clear();
        for(int i=0;i<inorder.size();i++){
            inmp[inorder[i]]=i;//Storing inorder in map element its index 
        }
    return arrayToTree(preorder,0,inorder.size()-1);;
    }
    TreeNode* arrayToTree(const vector<int>&preorder, int left, int right){
        if(left>right)
        return NULL;
        //Pick current root from preorder
        int root_val=preorder[pre_indx++];
        TreeNode* root= new TreeNode(root_val);
        //Find the root index in inorder map to determine subtree boundaries
        int mid=inmp[root_val];
        //Recursive left and right to build BST
        root->left=arrayToTree(preorder,left,mid-1);
        root->right=arrayToTree(preorder,mid+1,right);

    return root;
    }
};
