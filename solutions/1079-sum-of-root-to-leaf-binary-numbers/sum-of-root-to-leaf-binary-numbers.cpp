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
    string x="";
    int ans=0;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        x+=('0'+root->val);
        if(!root->left && !root->right){
            int mul=1;
            for(int i=x.size()-1;i>=0;i--){
                ans+=mul*(x[i]-'0');
                mul*=2;
            }
            x.pop_back();
            return;
        }
        dfs(root->left);
        dfs(root->right);
        x.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};