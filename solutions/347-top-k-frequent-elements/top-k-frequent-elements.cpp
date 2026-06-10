class Solution {
public:

    // TODO: Other efficient Algorithms to code

    // topKFrequent__map_heap_optimized
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        priority_queue<pair<int,int>> pq; // acting as min heap [storing -ves in max heap]
        for(auto x: nums){
            mp[x]++;
        }
        // nlogk
        for(auto [x,y]: mp){
            pq.push({-y,x});
            if(pq.size()>k){
                pq.pop();
            }
        }
        // klogk
        while(!pq.empty()){
            ans.push_back(pq.top().second); // .second is still positive
            pq.pop();
        }
        return ans;
    }

    vector<int> topKFrequent__map_heap(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        priority_queue<pair<int,int>> pq; // default max heap
        for(auto x: nums){
            mp[x]++;
        }
        //nlogn
        for(auto [x,y]: mp){
            pq.push({y,x});
        }
        int cnt=0;
        // klogn
        while(!pq.empty() && cnt<k){
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;
    }
};