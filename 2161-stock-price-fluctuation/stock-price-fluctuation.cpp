class StockPrice {
public:
    unordered_map<int,int>mp;
    set<pair<int,int>>st;
    int latest = 0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)){
            int old = mp[timestamp];
            st.erase({old,timestamp});
            st.insert({price,timestamp});
            latest = max(latest,timestamp);
            mp[timestamp] = price;
            return;
        }
        st.insert({price,timestamp});
        latest = max(latest,timestamp);
        mp[timestamp] = price;
    }
    
    int current() {
        return mp[latest];
    }
    
    int maximum() {
        auto it = prev(st.end());
        return (*it).first;
    }
    
    int minimum() {
        auto it = st.begin();
        return (*it).first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */