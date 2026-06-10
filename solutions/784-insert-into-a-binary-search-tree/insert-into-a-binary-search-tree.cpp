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

    void getParent(TreeNode* root, int val, TreeNode* &par){
        if(!root){
            return;
        }
        par=root;
        if(root->val>val){
            getParent(root->left,val,par);
        }else{
            getParent(root->right,val,par);
        }
    }

    TreeNode* insertIntoBST__fetch_and_update(TreeNode* root, int val) {
        TreeNode* par=NULL;
        getParent(root,val,par);
        if(par==NULL){
            return new TreeNode(val); 
        }
        if(par->val>val){
            par->left=new TreeNode(val);
        }else{
            par->right=new TreeNode(val);
        }
        return root;
    }

    // ====== ======     EASY STRAIGHTFORWARD     ==== ==========
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        if(root->val>val){
            root->left=insertIntoBST(root->left,val);
        }else{
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }

    // ====== ======  METHOD2: Iterative     ==== ==========
    /*

                    class Solution {
                        public TreeNode insertIntoBST(TreeNode root, int val) {
                            TreeNode node = root;
                            while (node != null) {
                            // insert into the right subtree
                            if (val > node.val) {
                                // insert right now
                                if (node.right == null) {
                                node.right = new TreeNode(val);
                                return root;
                                }
                                else node = node.right;
                            }
                            // insert into the left subtree
                            else {
                                // insert right now
                                if (node.left == null) {
                                node.left = new TreeNode(val);
                                return root;
                                }
                                else node = node.left;
                            }
                            }
                            return new TreeNode(val);
                        }
                        }
    */
};