class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bit = 0; bit < 31; bit++){
            //i have to set this bit in all elements and
            //then find strictly increasing
            vector<int>dp;
            for(int i = 0; i < n; i++){
                int val = nums[i];
                //so if this numbers bit is set then i can have this in my LIS
                if((val&(1<<bit)) == 0) continue;

                auto it = lower_bound(dp.begin(),dp.end(),val);
                if(it == dp.end()){
                    dp.push_back(val);
                }else{
                    *it = val;
                }
                ans = max(ans,(int)dp.size());
            }
        }
        return ans;
    }
};