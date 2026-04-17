class Solution {
public:
    int rev(int val){
        int t = 0;
        while(val > 0){
            t = t*10 + val%10;
            val /= 10;
        }
        return t;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,int>mp;
        for(int i = n-1; i >= 0; i--){
            int val = nums[i];
            int reverse = rev(val);
            if(mp.find(reverse) != mp.end()){
                ans = min(ans,abs(mp[reverse]-i));
            }
            mp[val] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};