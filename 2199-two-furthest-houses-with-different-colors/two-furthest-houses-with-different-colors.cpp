class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int color = colors[i];
            for(auto &[c,idx] : mp){
                if(c != color) ans = max(ans,(i-idx));
            }
            if(mp.find(color) == mp.end()) mp[color] = i;
        }
        return ans;
    }
};