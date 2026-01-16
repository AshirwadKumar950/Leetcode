class Solution {
public:
    const int MOD = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        //the values which are not present in both is already common for both
        //we need to find max common i can get from both
        unordered_set<int>v1;
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        int s1 = h.size(), s2 = v.size();
        int ans = INT_MIN;
        for(int i = 0; i < s1; i++){
            for(int j = i+1; j < s1; j++){
                v1.insert(abs(h[i]-h[j]));
            }
        }
        for(int i = 0; i < s2; i++){
            for(int j = i+1; j < s2; j++){
                int val = abs(v[i]-v[j]);
                if(v1.find(val) != v1.end()) ans = max(ans,val);
            }
        }
        return ans == INT_MIN ? -1 : 1ll*ans*ans%MOD;
    }
};