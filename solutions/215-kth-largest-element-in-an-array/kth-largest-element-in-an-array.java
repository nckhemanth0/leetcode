class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n=nums.length;
        Queue<Integer> q=new PriorityQueue<>(Comparator.naturalOrder());
        for(int i=0;i<n;i++){
            q.offer(nums[i]);
            if(q.size()>k){
                q.poll();
            }
        }
        return q.peek();
    }
}