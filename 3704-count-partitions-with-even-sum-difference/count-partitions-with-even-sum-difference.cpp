class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int runningsum = 0;
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            int rightsum = sum - runningsum;
            int leftsum = runningsum;
            if (abs(rightsum-leftsum)%2 == 0) {
                result++;
            }
        }
        return result;
    }
};