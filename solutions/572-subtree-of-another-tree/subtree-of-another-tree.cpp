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
    string subtree="";
    bool ans=false;
    string ser(TreeNode* root){
        if(!root){
            return "#";
        }
        string subtree=to_string(root->val)+","+ser(root->left)+","+ser(root->right);
        return subtree;
    }
    string dfs(TreeNode* root){
        if(!root){
            return "#";
        }
        string val=to_string(root->val)+","+dfs(root->left)+","+dfs(root->right);
        if(subtree==val){
            ans=true;
        }
        return val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subtree=ser(subRoot);
        dfs(root);
        return ans;
    }
};


/*

class Solution__ {
public:

    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }
        return root->val==subRoot->val && check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }
        return check(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

};

    /*
         TODO: Check other two approaches in Solution
            1. serialization
            2. tree hash method
    */


