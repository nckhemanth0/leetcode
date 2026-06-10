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

    int ans=INT_MIN;

    int rec(TreeNode* root){ // root included path
        if(!root){
            return 0;
        }
        int left_included=max(rec(root->left),0); // left included path
        int right_included=max(rec(root->right),0); // right included path
        ans=max({ans,root->val+left_included+right_included});
        return root->val+max({left_included,right_included});
    }

    int maxPathSum(TreeNode* root) {
        rec(root);
        return ans;
    }


    // ======= ======== Brute Force ======= ========

    /*
                    class Solution {
                        public:
                            // collect all nodes so we can start a DFS from each
                            void collect(TreeNode* u, vector<TreeNode*>& nodes) {
                                if (!u) return;
                                nodes.push_back(u);
                                collect(u->left, nodes);
                                collect(u->right, nodes);
                            }

                            void dfsFromStart(TreeNode* u, TreeNode* parent, long long cur,
                                            long long& best) {
                                cur += u->val;                // extend current path to u
                                best = max(best, cur);        // every visited node defines a path sum from the start
                                if (u->left  && u->left  != parent) dfsFromStart(u->left,  u, cur, best);
                                if (u->right && u->right != parent) dfsFromStart(u->right, u, cur, best);
                            }

                            int maxPathSumBrute(TreeNode* root) {
                                if (!root) return 0;
                                vector<TreeNode*> nodes;
                                collect(root, nodes);

                                long long best = LLONG_MIN;
                                for (TreeNode* s : nodes) {
                                    dfsFromStart(s, nullptr, 0, best);
                                }
                                return (int)best;
                            }
                        };
    */
};