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

    unordered_map<TreeNode*,unordered_map<int,int>> mp;

    int rec(TreeNode* root, int prev){
        if(!root){
            return 0;
        }
        if(mp.find(root)!=mp.end() && mp[root].find(prev)!=mp[root].end()){
            return mp[root][prev];
        }
        int ans=INT_MIN;
        if(prev){
            ans=max(ans,rec(root->left,0)+rec(root->right,0));
        }else{
            int take=rec(root->left,1)+rec(root->right,1)+root->val;
            int nottake=rec(root->left,0)+rec(root->right,0);
            ans=max({ans, take, nottake});
        }
        return mp[root][prev]=ans;
    }

    int rob(TreeNode* root) {
        return rec(root,0);
    }

    // ====== ====== ====== ====== ====== ====== ====== ====== ====== ======
    /*
        TODO: try and understand another dp approaches in solution!
    */
};