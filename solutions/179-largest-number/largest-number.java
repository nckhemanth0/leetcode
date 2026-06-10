class Solution {
    public String largestNumber(int[] nums) {
        List<String> arr=Arrays.stream(nums).boxed().map(x->String.valueOf(x)).collect(Collectors.toList());
        arr.sort((a,b) -> {
            return (b+a).compareTo(a+b);
            // int i=0;
            // int n=Integer.min(a.length(),b.length());
            // int maxi=Integer.max(a.length(),b.length());
            // while(i<n){
            //     if(a.charAt(i)!=b.charAt(i)){
            //         return b.compareTo(a);
            //     }
            //     i++;
            // }
            // if(maxi==n){
            //     return -1;
            // }
            // char first=a.charAt(i-1);
            // char next;
            // if(i<a.length()){
            //     next=a.charAt(i);
            //     if(next<first){
            //         return 1;
            //     }else{
            //         return -1;
            //     }
            // }else{
            //     next=b.charAt(i);
            //     if(next<first){
            //         return -1;
            //     }else{
            //         return 1;
            //     }
            // }
        });
        if (arr.get(0).equals("0")) return "0";
        StringBuilder sb=new StringBuilder();
        for(var x: arr){
            sb.append(x);
        }
        return sb.toString();
    }
}