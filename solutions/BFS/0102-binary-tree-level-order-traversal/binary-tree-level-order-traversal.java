/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null){
            return new ArrayList<>();
        }
        Queue<TreeNode> q=new ArrayDeque<>();
        List<List<Integer>> ans=new ArrayList<>();
        q.offer(root);
        while(!q.isEmpty()){
            List<Integer> level=new ArrayList<>();
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode u=q.poll();
                level.add(u.val);
                if(u.left!=null){
                    q.offer(u.left);
                }
                if(u.right!=null){
                    q.offer(u.right);
                }
            }
            ans.add(level);
        }
        return ans;
    }
}