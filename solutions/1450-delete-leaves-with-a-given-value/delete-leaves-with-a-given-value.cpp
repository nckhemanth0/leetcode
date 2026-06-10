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
    int cnt=0;
    // TC: n^2 in worst case -> did optimization below by conveting from preorder to postorder
    TreeNode* rec(TreeNode* root, int target) {
        if(!root){
            return NULL;
        }
        if(root->val==target && root->left==NULL && root->right==NULL){
            cnt++;
            return NULL;
        }
        root->left=rec(root->left,target);
        root->right=rec(root->right,target);
        return root;
    }

    TreeNode* removeLeafNodes__(TreeNode* root, int target) {
        while(1){
            root=rec(root,target);
            if(cnt==0){
                return root;
            }
            cnt=0;
        }
    }

    // ======== ======== Optimized in TC for aboveBelow is in O(N) ======== ========

    TreeNode* rec2(TreeNode* root, int target) {
        if(!root){
            return NULL;
        }
        root->left=rec2(root->left,target);
        root->right=rec2(root->right,target);
        if(root->val==target && root->left==NULL && root->right==NULL){
            return NULL;
        }
        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return rec2(root,target);
    }
};