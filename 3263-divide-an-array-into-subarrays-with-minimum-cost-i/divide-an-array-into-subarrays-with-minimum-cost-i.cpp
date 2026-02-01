class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];
        int n = nums.size();
        int s = min(nums[1],nums[2]);
        int ss = max(nums[1],nums[2]);
        for(int i = 3; i < n; i++){
            if(nums[i] < s){
                ss = s;
                s = nums[i];
                
            }else if(nums[i] >= s && nums[i] <= ss){
                ss = nums[i];
            }
        }
        return cost + s + ss;
    }
};