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
    unordered_map<int,int> delMp;
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode* root){
        if(!root){
            return nullptr;
        }
        root->left=dfs(root->left);
        root->right=dfs(root->right);
        if(delMp[root->val]){
            if(root->left!=nullptr){
                ans.push_back(dfs(root->left));
            }
            if(root->right!=nullptr){
                ans.push_back(dfs(root->right));
            }
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x: to_delete){
            delMp[x]++;
        }
        if(dfs(root)){
            ans.push_back(root);
        }
        return ans;
    }
};

/*
update nodes using post order
*/