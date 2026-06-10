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

    /*
        diameter can be:
            1. without current node => thats y we need to keep track of left and right node's diameter
                a. left diameter
                b. right diameter
            2. with current node
                a. max depth of left node + max depth of right node 
    */


    struct st{
        int h,d;
    };

    st rec(TreeNode* root){
        if(!root){
            return {0,0};
        }
        st left=rec(root->left);
        st right=rec(root->right);
        return {max(left.h,right.h)+1, max({left.h+right.h, left.d, right.d})};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        st ans=rec(root);
        return ans.d;
    }

    // ======= ======= ======= ======= ======= ======= ======= =======
    int diameter=0;

    int fun(TreeNode* root){
        if(!root){
            return 0;
        }
        int l=fun(root->left);
        int r=fun(root->right);
        diameter=max(diameter,l+r);
        return max(l,r)+1;
    }


    int diameterOfBinaryTree__global_var(TreeNode* root) {
        
        int ans=fun(root);
        return diameter;
    }

};