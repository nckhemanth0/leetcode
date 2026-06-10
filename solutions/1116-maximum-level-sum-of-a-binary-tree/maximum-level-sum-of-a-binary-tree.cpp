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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=-1e9-1,ans=0,cnt=1;
        while(!q.empty()){
            int sz=q.size(), sum=0;
            while(sz--){
                TreeNode* p=q.front();
                q.pop();
                sum+=(p->val);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            if(maxi<sum){
                maxi=sum;
                ans=cnt;
            }
            cnt++;
        }
        return ans;
    }
};