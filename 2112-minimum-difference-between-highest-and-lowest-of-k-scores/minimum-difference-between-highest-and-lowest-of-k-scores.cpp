class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, r = 0;
        int score = INT_MAX;
        while(r < n){
            if(r-l+1 == k){
                score = min(score,nums[r]-nums[l]);
                l++;
            }
            r++;
        }
        return score;
    }
};