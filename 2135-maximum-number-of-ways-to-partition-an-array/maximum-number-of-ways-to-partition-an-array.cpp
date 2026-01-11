class Solution {
public:
    typedef long long ll;
    int waysToPartition(vector<int>& nums, int k) {
        ll ways = 0;
        int n = nums.size();
        ll ts = 0;
        vector<ll>pref(n);
        unordered_map<ll,int>rightcount,leftcount;
        for(int i = 0; i < n; i++){
            ts += nums[i];
            pref[i] = ts;
        }
        ll s = 0;
        for(int i = 0; i < n-1; i++){
            s += nums[i];
            ll rs = ts - s;
            if(rs == s)ways++;
            rightcount[s]++;
        }
        for(int i = 0; i < n; i++){
            
            ll newts = ts - nums[i] + k;
            if(newts%2 == 0){
                ll t = newts/2;
                ll change = k - nums[i];
                ways = max(1ll*ways,1ll*leftcount[t]+rightcount[t-change]);
            }

            //if(i < n-1){
                leftcount[pref[i]]++;
                rightcount[pref[i]]--;
            //}
        }
        return ways;
    }
};