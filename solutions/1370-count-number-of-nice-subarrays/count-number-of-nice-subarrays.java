class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer> mp=new HashMap<>();
        mp.put(0,1);
        int odds=0,ans=0;;
        for(int i=0;i<n;i++){
            if((nums[i]&1)==1){
                odds++;
            }
            if(mp.containsKey(odds-k)){
                ans+=(mp.get(odds-k));
            }
            mp.put(odds,mp.getOrDefault(odds,0)+1);
        }
        return ans;
    }
}