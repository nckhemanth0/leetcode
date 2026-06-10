class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        // can also use unordered_set as well
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }
        int ans=0;
        for(auto [x,y]: mp){ // here x's are unique or indirectly set keys like in unordered_set
            if(mp.find(x-1)==mp.end()){
                int cnt=1;
                while(mp.find(x+cnt)!=mp.end()){
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }

    // Step 1: Initializing DSU (for loop)
    //     Each number is inserted into parent and rank. O(n)
    // Step 2: Union Operations (for loop)
    //     Each find() operation has path compression, making it O(α(n)).
    //     Union operations are amortized O(α(n)).
    //     Since we call unionSet() at most twice per element, this step is O(n α(n)) ≈ O(n).
    // Step 3: Finding the Maximum Component Size
    //     We call find() for each element, which runs in O(α(n)).
    //     Total complexity: O(n α(n)) ≈ O(n).
    //     Final Time Complexity:O(n)
    unordered_map<int, int> parent; // Stores parent of each element
    unordered_map<int, int> rank;   // Stores size of each component
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return; // Already connected
        // Union by rank (size)
        if (rank[rootX] >= rank[rootY]) {
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        } else {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
    int longestConsecutive__UnionFind(vector<int>& nums) {
        if (nums.empty()) return 0;
        // Initialize DSU
        for (int num : nums) {
            // case is redundant since we are gonna update to same values
            if (parent.find(num) == parent.end()) { // Avoid duplicates
                parent[num] = num;
                rank[num] = 1;
            }
        }
        // Perform union for adjacent numbers
        for (int num : nums) {
            if (parent.find(num - 1) != parent.end()) {
                unionSet(num, num - 1);
            }
            if (parent.find(num + 1) != parent.end()) {
                unionSet(num, num + 1);
            }
        }
        // Find the maximum size component
        int maxSize = 0;
        for (auto& [num, _] : parent) {
            maxSize = max(maxSize, rank[find(num)]);
        }
        return maxSize;
    }

    // ================

    int longestConsecutive__1pointer_till_head_ans(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1,ans=1,n=nums.size();
        for(int head=1;head<n;head++){
            if(nums[head]==nums[head-1]){
                continue;
            }
            if(nums[head]==nums[head-1]+1){
                cnt++;
            }else{
                cnt=1;
            }
            ans=max(ans,cnt); // till head what is the possible answer
        }
        return ans;
    }

    int longestConsecutive__2pointer(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int head=-1,tail=0,ans=0,n=nums.size();
        while(tail<n){
            set<int> s;
            while((head+1)<nums.size() && (head<tail || (nums[head]+1==nums[head+1]) || (nums[head]==nums[head+1]))){
                head++;
                s.insert(nums[head]);
            }
            int size=s.size();
            ans=max(ans,size);
            if(head<tail){
                tail++;
                head=tail-1;
            }else{
                tail=head+1;
            }
        }
        return ans;
    }
};