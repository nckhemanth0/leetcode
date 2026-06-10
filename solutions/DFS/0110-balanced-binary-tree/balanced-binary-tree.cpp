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

    int rec(TreeNode* root, int &ans){
        if(!root){
            return 0;
        }
        if(ans==0){ // early pruning if found answer
            return 0;
        }
        int left=rec(root->left,ans);
        int right=rec(root->right,ans);
        ans&=(abs(left-right)<=1);
        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
        int ans=1;
        rec(root,ans);
        return ans;
    }
};