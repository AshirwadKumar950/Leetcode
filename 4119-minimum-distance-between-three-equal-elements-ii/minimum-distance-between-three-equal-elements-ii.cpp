class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &[k,vec] : mp){
            if(vec.size() < 3) continue;
            int l = vec.size();
            for(int i = 0; i <= l-3; i++){
                int v1 = vec[i], v2 = vec[i+1], v3 = vec[i+2];
                int value = abs(v1-v2)+abs(v2-v3)+abs(v1-v3);
                ans = min(ans,value); 
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};