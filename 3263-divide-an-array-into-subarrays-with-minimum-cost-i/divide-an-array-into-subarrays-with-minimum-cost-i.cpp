class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];
        int n = nums.size();
        vector<int>arr(nums.begin()+1,nums.end());
        sort(arr.begin(),arr.end());
        return cost + arr[0] + arr[1];
    }
};