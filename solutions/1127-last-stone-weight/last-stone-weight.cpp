class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        multiset<int> ms;
        for(int i=0;i<n;i++){
            ms.insert(stones[i]);
        }
        while(ms.size()>1){
            auto it1=prev(ms.end());
            int first=*it1;
            ms.erase(it1);

            auto it2=prev(ms.end());
            int second=*it2;
            ms.erase(it2);

            ms.insert(abs(first-second));
        }
        return *ms.begin();
    }
};