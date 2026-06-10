class Solution {
public:
    int n1,n2;
    vector<vector<vector<int>>> dp;
    int rec(int i, int j, int picked, vector<int>& nums1, vector<int>& nums2){
        if(i>=n1 || j>=n2){
            if(picked==0){
                return -1e6-1;
            }
            return 0;
        }
        if(dp[i][j][picked]!=-1){
            return dp[i][j][picked];
        }
        int ans1=rec(i+1,j+1,1,nums1,nums2)+nums1[i]*nums2[j];
        // possibility if nothing gets picked is done using cnt
        int ans2=rec(i,j+1,picked,nums1,nums2);
        int ans3=rec(i+1,j,picked,nums1,nums2);
        return dp[i][j][picked]=max({ans1,ans2,ans3});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size(), n2=nums2.size();
        dp.resize(n1,vector<vector<int>>(n2, vector<int>(2,-1)));
        return rec(0,0,0,nums1,nums2);
    }
};


/*                       1D DP Iterative solution - UNDERSTANDABLE

        class Solution {
        public:
            int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
                int firstMax = INT_MIN;
                int secondMax = INT_MIN;
                int firstMin = INT_MAX;
                int secondMin = INT_MAX;
                
                for (int num: nums1) {
                    firstMax = max(firstMax, num);
                    firstMin = min(firstMin, num);
                }
                
                for (int num: nums2) {
                    secondMax = max(secondMax, num);
                    secondMin = min(secondMin, num);
                }
                
                if (firstMax < 0 && secondMin > 0) {
                    return firstMax * secondMin;
                }
                
                if (firstMin > 0 && secondMax < 0) {
                    return firstMin * secondMax;
                } 

                int m = nums2.size() + 1;
                vector<int> dp(m, 0);
                vector<int> prevDp(m, 0);
                
                for (int i = nums1.size() - 1; i >= 0; i--) {
                    dp = vector(m, 0);
                    for (int j = nums2.size() - 1; j >= 0; j--) {
                        int use = nums1[i] * nums2[j] + prevDp[j + 1];
                        dp[j] = max(use, max(prevDp[j], dp[j + 1]));
                    }
                    
                    prevDp = dp;
                }
                
                return dp[0];
            }
        };
*/