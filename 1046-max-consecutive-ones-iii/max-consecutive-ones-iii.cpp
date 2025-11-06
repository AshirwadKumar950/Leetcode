class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int c = 0;
        int l = 0;
        bool noone = true;
        for(int r = 0; r < n; r++){
            if(nums[r] == 0) c++;
            if(nums[r] == 1) noone = false;
            while(l < r && c > k){
                if(nums[l] == 0) c--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return noone && k == 0 ? 0 : ans;
    }
};