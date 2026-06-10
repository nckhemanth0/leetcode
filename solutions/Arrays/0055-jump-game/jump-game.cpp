class Solution {
public:
    bool canJump__(vector<int>& nums) {
        int n=nums.size();
        int last=0;
        for(int i=0;i<n;i++){
            if(i>last){
                return false;
            }
            last=max(last,i+nums[i]);
        }
        return true;
    }

    // =======


    /*

                    enum Index { GOOD, BAD, UNKNOWN };
                    class Solution {
                    public:
                        vector<Index> memo;
                        bool canJumpFromPosition(int position, vector<int>& nums) {
                            if (memo[position] != UNKNOWN) {
                                return memo[position] == GOOD ? true : false;
                            }
                            int furthestJump = min(position + nums[position], (int)nums.size() - 1);
                            for (int nextPosition = position + 1; nextPosition <= furthestJump;
                                nextPosition++) {
                                if (canJumpFromPosition(nextPosition, nums)) {
                                    memo[position] = GOOD;
                                    return true;
                                }
                            }
                            memo[position] = BAD;
                            return false;
                        }
                        bool canJump(vector<int>& nums) {
                            memo = vector<Index>(nums.size());
                            for (int i = 0; i < memo.size(); i++) {
                                memo[i] = UNKNOWN;
                            }
                            memo[memo.size() - 1] = GOOD;
                            return canJumpFromPosition(0, nums);
                        }
                    };

    */

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        if (nums[0] == 0) return false;

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        int farthest = 0; // highest index we’ve already expanded

        while (!q.empty()) {
            int i = q.front(); q.pop();

            // Expand only beyond the region we already processed
            int start = max(i + 1, farthest + 1);
            int end   = min(n - 1, i + nums[i]);

            for (int j = start; j <= end; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    if (j == n - 1) return true;
                    q.push(j);
                }
            }

            farthest = max(farthest, end); // move rightward frontier
        }

        return vis[n - 1];
    }

};