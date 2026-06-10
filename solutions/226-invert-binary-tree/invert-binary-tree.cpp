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

    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        swap(root->left,root->right);
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }

    // ======= ======= ======= ======= ======= ======= =======

    TreeNode* invertTree__kinda_post_order(TreeNode* root) {
        if(!root){
            return NULL;
        }
        TreeNode* temp=invertTree(root->right);
        root->right=invertTree(root->left);
        root->left=temp;
        return root;
    }

};