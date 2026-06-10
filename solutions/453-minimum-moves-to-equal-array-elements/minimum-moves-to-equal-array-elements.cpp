class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        for(auto x: nums){
            mini=min(mini,x);
        }
        int ans=0;
        for(auto x: nums){
            ans+=(x-mini);
        }
        return ans;
    }
};

/*

1 1 1 3 3 5 2 => 5 5 5 7 5 6 => 7 7 7 7 7 8 => 8 8 8 8 8 8

4,2,1

*/

// 1 1 1 2 3 3 5 => 5 5 5 6 7 5 => 7 7 7 8 7 7

// x1,x2,x3,x4,x5,x6

// x6-x1
// x6-x5
// x6-x5
