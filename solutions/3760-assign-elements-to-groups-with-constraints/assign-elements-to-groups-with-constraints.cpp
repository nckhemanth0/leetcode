class Solution {
public:
    typedef long long int ll;
    vector<int> nums;
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        nums.resize(100001,-1);
        int cnt=0;
        for(auto x: elements){
            if(nums[x]!=-1){
                cnt++;
                continue;
            }
            for(int i=1;x*i<=1e5;i++){ // instead of 1e5, can use maxi of #groups
                if(nums[x*i]==-1){
                    nums[x*i]=cnt;
                }
            }
            cnt++;
        }
        for(int i=0;i<groups.size();i++){
            groups[i]=nums[groups[i]];
        }
        return groups;
    }
};