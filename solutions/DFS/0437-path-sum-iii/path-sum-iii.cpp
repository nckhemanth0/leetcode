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
    long long ans=0;
    unordered_map<long long,long long> mp;
    void rec(TreeNode* root, long long &sum, int t){
        if(!root){
            return;
        }
        sum+=root->val;
        if(mp.count(sum-t)){
            ans+=mp[sum-t];
        }
        mp[sum]++;
        rec(root->left,sum,t);
        rec(root->right,sum,t);
        mp[sum]--;
        sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long sum=0;
        mp[0]=1;
        rec(root,sum,targetSum);
        return ans;
    }
};