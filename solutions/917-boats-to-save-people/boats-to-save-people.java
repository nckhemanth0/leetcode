class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int n=people.length;
        Arrays.sort(people);
        int i=0,j=n-1,ans=0;
        while(i<j){
            if(people[i]+people[j]>limit){
                j--;
            }else{
                i++;j--;
            }
            ans++;
        }
        if(i==j) ans++;
        return ans;
    }
}

// 3 3 4 5