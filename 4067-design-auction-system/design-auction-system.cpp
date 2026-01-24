/*
    works i have to do -
    addBid(int userId, int itemId, int bidAmount)
    add this users bid for this specific itemId with this amount
    if this user has already a bid on this item replace it

    updateBid(int userId, int itemId, int newAmount)
    for this userId update this itemId bid 
    
    removeBid(int userId, int itemId)
    remove this userId bid for this itemId

    getHighestBidder(int itemId)
    return the userId of the highest bidder for itemId
*/
class AuctionSystem {
public:
    unordered_map<int,unordered_map<int,int>>itemTouser;
    unordered_map<int,set<pair<int,int>>>get;//for this item highest bid amount
    //put map[itemId].insert({bidAmount,userId});
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(itemTouser[itemId].count(userId)){
            //remove oldvalue for this user
            int oldVal = itemTouser[itemId][userId];
            get[itemId].erase({oldVal,userId});
        }
        itemTouser[itemId][userId] = bidAmount;
        get[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldVal = itemTouser[itemId][userId];
        get[itemId].erase({oldVal,userId});
        itemTouser[itemId][userId] = newAmount;
        get[itemId].insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        int bidCost = itemTouser[itemId][userId];
        itemTouser[itemId].erase(userId);
        get[itemId].erase({bidCost,userId});
    }
    
    int getHighestBidder(int itemId) {
        if(get[itemId].empty()) return -1;
        auto it = get[itemId].rbegin();
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