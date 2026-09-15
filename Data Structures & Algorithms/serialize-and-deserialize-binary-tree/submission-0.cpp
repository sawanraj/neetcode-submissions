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

class Codec {
public:
     
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        
        serializehelper(root,data);

        return data;
    }
    void serializehelper(TreeNode* root, string &data){
        if(!root){
            data += "N,";
        return;
        }

        data += to_string(root->val) + ",";
        serializehelper(root->left, data);
        serializehelper(root->right, data);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializehelper(ss);
    }
    TreeNode* deserializehelper(stringstream &ss){
        string val;
        if(!getline(ss,val,',')){
            return NULL;
        }
        if(val == "N"){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserializehelper(ss);
        root->right=deserializehelper(ss);
        
        return root;
    }
};
