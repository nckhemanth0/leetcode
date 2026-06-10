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

    struct st{
        long long min, max;
    };

    // Could make mistake: see here even if current node w.r.t its left and right satisfy the BST properly, it might fail for other child nodes. In the end we only get the rec value of root node. So since every node should satisfy this cond, we need to accumulate this with ans variable.
    st rec(TreeNode* root, int &ans) {
        if(!root){
            return {LLONG_MAX,LLONG_MIN};
        }
        st left=rec(root->left, ans);
        st right=rec(root->right, ans);
        ans&=(left.max<root->val && right.min>root->val);
        return {min(1LL*root->val, left.min),max(1LL*root->val,right.max)};
    }

    bool isValidBST__Range_accumulation(TreeNode* root) {
        int ans=1;
        rec(root,ans);
        return ans;
    }

    // ============ ============ Inorder Recursion maintaining the previous node ============ ============

    TreeNode* prev=NULL;
    int ans=1;

    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        if(prev && root->val<=prev->val){
            ans&=0;
        }
        prev=root; // whatever node processed before, that will be the previous node!
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }

    // ========= =========== Other observation: rec from top to bottom  =========== ============

    /*
            bool isBstUtil(Node* root, long long minVal, long long maxVal) {
                if(root == NULL) return true;
                if(root->val <= minVal || root->val >= maxVal) return false;
                return isBstUtil(root->left, minVal, root->val) && isBstUtil(root->right, root->val, maxVal);
            }

            bool isBst(Node* root) {
                //Complete the function
                return isBstUtil(root, LLONG_MIN, LLONG_MAX);
            }
    */

    // ========= Other observation: inorder using stack from property if 1st ele < 2nd ele <,.... all elements,then it is in BST ===========

    /*
        Tweak: keep a prev variable to keep track of last processed/popped element to compare iteratively

                    class Solution {
                        public:
                            bool isValidBST(TreeNode* root) {
                                stack<TreeNode*> stk;
                                TreeNode* prev = nullptr;

                                while (!stk.empty() or root != nullptr) {
                                    while (root != nullptr) {
                                        stk.push(root);
                                        root = root->left;
                                    }
                                    root = stk.top();
                                    stk.pop();

                                    // If next element in inorder traversal
                                    // is smaller than the previous one
                                    // that's not BST.
                                    if (prev != nullptr and root->val <= prev->val) {
                                        return false;
                                    }
                                    prev = root;
                                    root = root->right;
                                }
                                return true;
                            }
                        };
    */
};