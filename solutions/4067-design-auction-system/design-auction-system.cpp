/*
    mp[userId][itemId]=bidAmount
    mp<itemId,set<pair<bidAmount,userId>>>
*/

class AuctionSystem {
public:
    unordered_map<int,unordered_map<int,int>> usermp;
    unordered_map<int,set<pair<int,int>>> itemmp;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(usermp.find(userId)==usermp.end() || usermp[userId].find(itemId)==usermp[userId].end()){
            itemmp[itemId].insert({bidAmount,userId});
        }else{
            itemmp[itemId].erase({usermp[userId][itemId],userId});
            itemmp[itemId].insert({bidAmount,userId});
        }
        usermp[userId][itemId]=bidAmount;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        itemmp[itemId].erase({usermp[userId][itemId],userId});
        itemmp[itemId].insert({newAmount,userId});
        usermp[userId][itemId]=newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        itemmp[itemId].erase({usermp[userId][itemId],userId});
        usermp[userId].erase(itemId);
    }
    
    int getHighestBidder(int itemId) {
        auto itMap = itemmp.find(itemId);
        if(itMap==itemmp.end() || itMap->second.empty()){
            return -1;
        }
        auto it=itemmp[itemId].end();
        it--;
        return it->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */

