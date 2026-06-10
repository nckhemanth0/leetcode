class Solution {
public:
    int numSubarraysWithSum__(vector<int>& nums, int goal) {
        int n=nums.size(),sum=0,ans=0;
        unordered_map<int,int> pre_sum;
        pre_sum[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(pre_sum.count(sum-goal)){
                ans+=pre_sum[sum-goal];
            }
            pre_sum[sum]++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),sum=0,ans=0;
        int left=0,right=0,prefixSum=0;
        for(;right<n;right++){
            sum+=nums[right];
            while((nums[left]==0 || sum>goal) && left<right){
                if(nums[left]==1){
                    prefixSum=0;
                }else{
                    prefixSum++;
                }
                sum-=nums[left];
                left++;
            }
            if(sum==goal){
                ans+=1+prefixSum;
            }
        }
        return ans;
    }


    // inefficient but got accepted => o(n^2) TC
    int numSubarraysWithSum__tp_sliding_window_n2(vector<int>& nums, int goal) {
        int n=nums.size(),sum=0,ans=0;
        int left=0,right=0;
        for(;right<n;right++){
            sum+=nums[right];
            while(sum>goal && left<right){
                sum-=nums[left];
                left++;
            }
            if(sum==goal){
                int cnt=0;
                int temp=left;
                while(temp<right && nums[temp]==0){
                    // prefix zeros
                    cnt++;
                    temp++;
                }
                // cout<<left<<" "<<right<<" "<<cnt<<endl;
                ans+=1+cnt;
            }
        }
        return ans;
    }


    /*

                wrong code!! => "direct sliding window" => cannot consider this approach

                Work only for max length subarray but not for count of subarrays

                        Test case where this fails:
                        nums = [1,0,1,0,1], goal = 2

                        For sum we get wrong we miss 2…4 indexed subarray. 
                        But for the longest subarray we get length 4 that is captured!


                int numSubarraysWithSum____(vector<int>& nums, int goal) {
                    int n=nums.size(),sum=0,ans=0;
                    unordered_map<int,int> pre_sum;
                    int left=0,right=0;
                    for(;right<n;right++){
                        sum+=nums[right];
                        while(sum>goal){
                            sum-=nums[left];
                            left++;
                        }
                        if(left<=right && sum==goal){
                            cout<<left<<" "<<right<<endl;
                            ans+=1;
                        }
                    }
                    return ans;
                }
    */
};