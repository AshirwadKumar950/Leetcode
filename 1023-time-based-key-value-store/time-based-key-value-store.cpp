class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &vec = mp[key];
        int lb = 0, ub = vec.size()-1;
        string ans;
        while(lb <= ub){
            int mid = lb + (ub-lb)/2;
            if(vec[mid].first <= timestamp){
                ans = vec[mid].second;
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */