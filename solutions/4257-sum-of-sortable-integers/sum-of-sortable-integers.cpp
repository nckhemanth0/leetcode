class Solution {
public:
    vector<int> divisors;
    void div(int n){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divisors.push_back(i);
                if(i!=(n/i)){
                    divisors.push_back((n/i));
                }
            }
        }
    }

    bool check(vector<int>& nums, int k){
        int n=nums.size();
        int i=0;
        int maxi=INT_MIN;
        while(i<n){
            for(int j=i;j<(i+k);j++){
                if(j!=0 && j>=k && nums[j]<maxi){
                                            cout<<"xxxxxx"<<endl;
                    return false;
                }
            }
            
            int st=i;
            maxi=max(maxi,nums[st]);
            int cnt=i+1;
            int c=0;
            int idx=st;
            while(cnt<(i+k)){
                maxi=max(maxi,nums[cnt]);
                if(nums[cnt]<nums[cnt-1]){
                    c++;
                    idx=cnt;
                }
                cnt++;
            }
            if(c>1){
                                        cout<<"zzzzz"<<endl;
                return false;
            }
            if(c==1){
                for(int j=idx;j<(i+k);j++){
                    if(nums[j]>nums[st]){
                        cout<<"yyyyy"<<endl;
                        return false;
                    }
                }
            }
            i=cnt;

        }
        return true;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        div(n);
        int ans=0;
        for(auto k: divisors){
            if(k==1 && is_sorted(nums.begin(),nums.end())){
                ans++;
            }
            if(k!=1 && check(nums,k)){
                ans+=k;
            }
        }
        return ans;
    }
};