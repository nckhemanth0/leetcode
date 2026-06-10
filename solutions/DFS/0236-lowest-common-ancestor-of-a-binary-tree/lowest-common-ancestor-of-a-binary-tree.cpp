/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution__1 {
public:
    unordered_map<TreeNode*, TreeNode*> parMp;
    unordered_map<TreeNode*, int> depthMp;
    void dfs(TreeNode* root, TreeNode* parent, int depth){
        parMp[root]=parent;
        depthMp[root]=depth;
        if(root->left!=nullptr){
            dfs(root->left,root,depth+1);
        }
        if(root->right!=nullptr){
            dfs(root->right,root,depth+1);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* parent=nullptr;
        dfs(root,parent,0);
        if(depthMp[p]<depthMp[q]){
            swap(p,q);
        }
        TreeNode* par1=p; TreeNode* par2=q;
        // can also use set to add all ancestors of one path. While moving to 2nd path we see if the node is in that set
        while(par1!=nullptr && par2!=nullptr && par1!=par2){
            if(depthMp[par1]>depthMp[par2]){
                par1=parMp[par1];
            }else if(depthMp[par1]<depthMp[par2]){
                par2=parMp[par2];
            }else{
                par1=parMp[par1];
                par2=parMp[par2];
            }
        }
        return par1;
    }
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((!root) || (root && (root==p || root==q))){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        return left?left:right;
    }
};