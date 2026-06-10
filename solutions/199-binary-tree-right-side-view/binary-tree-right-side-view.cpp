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
    vector<int> rightSideView__from_Lvl_order_traversal_1(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int cnt=0;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(cnt==0){
                    ans.push_back(node->val);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
                cnt++;
            }
        }
        return ans;
    }

    vector<int> rightSideView_2(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int val;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                val=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(val);
        }
        return ans;
    }

    // ======== ======== ======== DFS ======== ======== ======== ========

    vector<int> rsv;

    void rec(TreeNode* root, int depth){
        if(!root){
            return;
        }
        if(depth==rsv.size()){ // size contains max depth seen so far
            rsv.push_back(root->val);
        }
        rec(root->right,depth+1);
        rec(root->left,depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        rec(root,0);
        return rsv;
    }

    /*

                    int maxDepthSeen = -1;
                    void leftView(Node* r, int d=0){
                        if(!r) return;
                        if(d > maxDepthSeen){ cout<<r->val<<" "; maxDepthSeen = d; }
                        leftView(r->left, d+1);
                        leftView(r->right, d+1);
                    }

    */

};