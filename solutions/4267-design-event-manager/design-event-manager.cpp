class cmp{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
        if(a.first!=b.first){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
};


class EventManager {
public:

    set<pair<int,int>,cmp> s;
    unordered_map<int,set<pair<int,int>,cmp>::iterator> mp;
    
    EventManager(vector<vector<int>>& events) {
        for(auto x: events){
            auto [it,done]=s.insert({x[1],x[0]});
            mp[x[0]]=it;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        auto it=mp[eventId];
        s.erase(it);
        auto [it2,done]=s.insert({newPriority,eventId});
        mp[eventId]=it2;
    }
    
    int pollHighest() {
        if(s.size()==0){
            return -1;
        }
        auto it=s.begin();
        int id=it->second;
        int val=it->first;
        s.erase(it);
        mp.erase(id);
        return id;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */