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

    int rec(TreeNode* root){
        if(!root){
            return 0;
        }
        int ld=rec(root->left);
        int rd=rec(root->right);
        return max(ld,rd)+1;
    }

    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return rec(root);
    }

    // ========

    void rec(TreeNode* root, int depth, int &ans){
        if(!root){
            return;
        }
        ans=max(ans,depth);
        rec(root->left,depth+1,ans);
        rec(root->right,depth+1,ans);
    }

    int maxDepth__top_to_bottom(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans=1;
        rec(root,1,ans);
        return ans;
    }

    /*
        // Observation: 
            If the problem asks “what’s the result at this node (from children)? -> Bottom-Up.” If it asks “what happens along the way from root to leaf? -> Top-Down.”
    */

    // =========
    /*
        We could also do dfs but note, since in binary tree we can have multiple nodes with same value, we should push node in queue not value like in graph bfs.
    */
};