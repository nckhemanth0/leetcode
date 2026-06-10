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
    int cnt=0;
    void rec(TreeNode* root, int max_so_far){
        if(!root){
            return;
        }
        if(root->val>=max_so_far){
            cnt++;
        }
        max_so_far=max(root->val, max_so_far);
        rec(root->left,max_so_far);
        rec(root->right,max_so_far);
    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        rec(root, -1e5);
        return cnt;
    }

    // ======== ======== ======== Method2: DFS ======== ======== ========

    /*
                        class Pair {
                            public TreeNode node;
                            public int maxSoFar;
                            
                            public Pair(TreeNode node, int maxSoFar) {
                                this.node = node;
                                this.maxSoFar = maxSoFar;
                            }
                        }

                        class Solution {
                            public int goodNodes(TreeNode root) {
                                int numGoodNodes = 0;
                                Stack<Pair> stack = new Stack<>();
                                stack.push(new Pair(root, Integer.MIN_VALUE));
                                
                                while (stack.size() > 0) {
                                    Pair curr = stack.pop();
                                    if (curr.maxSoFar <= curr.node.val) {
                                        numGoodNodes++;
                                    }
                                    
                                    if (curr.node.left != null) {
                                        stack.push(new Pair(curr.node.left, Math.max(curr.node.val, curr.maxSoFar)));
                                    }
                                    
                                    if (curr.node.right != null) {
                                        stack.push(new Pair(curr.node.right, Math.max(curr.node.val, curr.maxSoFar)));
                                    }
                                }

                                return numGoodNodes;
                            }
                        }
    */

    // ======== ======== ======== Method3: BFS ======== ======== ========

    /*
                        class Pair {
                            public TreeNode node;
                            public int maxSoFar;
                            
                            public Pair(TreeNode node, int maxSoFar) {
                                this.node = node;
                                this.maxSoFar = maxSoFar;
                            }
                        }

                        class Solution {
                            public int goodNodes(TreeNode root) {
                                int numGoodNodes = 0;
                                Queue<Pair> queue = new LinkedList<>();
                                queue.offer(new Pair(root, Integer.MIN_VALUE));
                                
                                while (queue.size() > 0) {
                                    Pair curr = queue.poll();
                                    if (curr.maxSoFar <= curr.node.val) {
                                        numGoodNodes++;
                                    }
                                    
                                    if (curr.node.right != null) {
                                        queue.offer(new Pair(curr.node.right, Math.max(curr.node.val, curr.maxSoFar)));
                                    }

                                    if (curr.node.left != null) {
                                        queue.offer(new Pair(curr.node.left, Math.max(curr.node.val, curr.maxSoFar)));
                                    }
                                }

                                return numGoodNodes;
                            }
                        }
    */

};