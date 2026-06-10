class Solution {
    public final int MOD=(int)1e9+7;
    public int threeSumMulti(int[] arr, int target) {
        int n=arr.length,ans=0;
        for(int i=0;i<n;i++){
            Map<Integer,Integer> mp=new HashMap<>();
            int nt=target-arr[i];
            for(int j=i+1;j<n;j++){
                if(mp.containsKey(nt-arr[j])){
                    ans=(ans%MOD+mp.get(nt-arr[j]))%MOD;
                }
                mp.put(arr[j],mp.getOrDefault(arr[j],0)+1);
            }
        }
        return ans;
    }
}

/*

1 1
2 2
3 2
4 2

*/