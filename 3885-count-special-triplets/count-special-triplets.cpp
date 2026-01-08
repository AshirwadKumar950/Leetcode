class Solution {
public:
typedef long long ll;
    const int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        ll count = 0;
        unordered_map<ll,ll>mp1,mp2;
        for(int i = 0; i < n; i++){
            mp2[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            mp2[nums[i]]--;
            if(mp2[nums[i]] == 0) mp2.erase(nums[i]);
            int val = nums[i];
            if(mp1.find(2*val) != mp1.end() && mp2.find(2*val) != mp2.end()){
                count = (count + (1ll*mp1[2*val]*mp2[2*val])%mod)%mod;
            }
            mp1[nums[i]]++;
        }
        return count;
    }
};