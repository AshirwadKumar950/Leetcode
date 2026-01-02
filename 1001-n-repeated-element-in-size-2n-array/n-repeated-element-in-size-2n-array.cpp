class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &val : nums){
            mp[val]++;
        }
        int ans = 0;
        int count = 0;
        for(auto &[k,f] : mp){
            if(f > count){
                count = f;
                ans = k;
            }
        }
        return ans;
    }
};