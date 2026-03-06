class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        //[1,3,5,7,9,11,13,15,17,19,21,23]
        //[1,2,3,4,5]
        int diff = nums[1] - nums[0];
        int cnt = 0;
        int ans = 0;
        for(int i = 2; i < n; i++){
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                cnt++;
                ans += cnt;
            }else cnt = 0;
        }
        return ans;
    }
};