/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void srec(TreeNode* root, ostringstream &out){
        if(!root){
            out<<"null"<<"#";
            return;
        }
        out<<root->val<<"#";
        srec(root->left,out);
        srec(root->right,out);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        srec(root,out);
        return out.str();
    }

    TreeNode* drec(istringstream &in){
        string val;
        if(!getline(in,val,'#')){
            return NULL;
        }
        if(val=="null"){
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(val));
        root->left=drec(in);
        root->right=drec(in);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return drec(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));