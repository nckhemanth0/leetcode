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
    vector<int> ans;

    void rec(TreeNode* root){
        if(!root){
            return;
        }
        rec(root->left);
        ans.push_back(root->val);
        rec(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        rec(root);
        return ans;
    }

    // ========= ========= ========= ========= ========= ========= ========= ========= =========

    // Method 3: Morris Order Traversal
    vector<int> getInorderTraversal(TreeNode* root) {
        //Complete the function
        vector<int> ans;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left!=NULL){
                TreeNode* temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur){
                    temp=temp->right;
                }
                if(temp->right==cur){
                    temp->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }else{
                    temp->right=cur;
                    cur=cur->left;
                }
            }else{
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }

    // ========= ========= ========= ========= ========= ========= ========= ========= =========

    // Method 2: Stack
    vector<int> getInorderTraversal__stack(TreeNode* root) {
        //Complete the function
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st; // so morris order is nothing but using links instead of stack to go to ancestor
        TreeNode* cur=root;
        while(cur!=NULL || !st.empty()){
            while(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            ans.push_back(cur->val);
            st.pop();
            cur=cur->right;
        }
        return ans;
    }
};