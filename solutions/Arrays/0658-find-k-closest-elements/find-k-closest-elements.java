class Solution {
    private int binSearch(int[] arr, int x){
        int n=arr.length;
        int lo=0,hi=n-1,ans=n;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(arr[mid]>=x){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n=arr.length;
        if(n==1){
            return Arrays.stream(arr).boxed().collect(Collectors.toList());
        }
        int idx=binSearch(arr,x);
        // System.out.println(idx);
        int j=idx;
        int i=idx-1;
        Deque<Integer> ans=new LinkedList<Integer>();
        while(i>=0 || j<n){
            // System.out.println(i+" "+j);
            if(ans.size()==k){
                // System.out.println(j-i-1);
                break;
            }
            if(i<0){
                ans.offerLast(arr[j++]);
            }else if(j>=n){
                ans.offerFirst(arr[i--]);
            }else{
                if(Math.abs(arr[i]-x)>Math.abs(arr[j]-x)){
                    ans.offerLast(arr[j++]);
                }else if(Math.abs(arr[i]-x)<=Math.abs(arr[j]-x)){
                    ans.offerFirst(arr[i--]);
                }
            }
        }
        return new ArrayList(ans);
    }
}