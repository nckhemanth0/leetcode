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
    int MOD=1e9+7;
    int getSum(TreeNode* &root){
        if(root==NULL){
            return 0;
        }
        return (root->val+getSum(root->left)+getSum(root->right));
    }
    int dfs(TreeNode* root, int sum, long long &ans){
        if(root==NULL){
            return 0;
        }
        int x=root->val+dfs(root->left,sum,ans)+dfs(root->right,sum,ans);
        // MOD here is wrong. A bigger product can become a smaller number after % MOD, max(modded) != mod(max)
        ans=max(ans,(x*(1LL*sum-x)));
        return x;
    }
    int maxProduct(TreeNode* root) {
        int sum=getSum(root); 
        long long ans=0;
        dfs(root,sum,ans);
        return ans%MOD;
    }
};

/*                      MOD MULTIPLICATION

            private int modularMultiplication(int a, int b, int m) {
                int product = 0;
                int currentSum = a;
                while (b > 0) {
                    int bit = b % 2;
                    b >>= 1;
                    if (bit == 1) {
                        product += currentSum;
                        product %= m;
                    }
                    currentSum <<= 1;
                    currentSum %= m;
                }
                return product;
            }  
*/

/*
    x(s-x)
    sx-x^2
    x=s/2
*/