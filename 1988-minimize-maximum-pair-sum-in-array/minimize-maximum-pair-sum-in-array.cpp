class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minval = INT_MIN;
        for(int i = 0, j = n-1; i < j; i++,j--){
            minval = max(minval,nums[i]+nums[j]);
        }
        return minval;
    }
};