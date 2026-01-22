class Solution {
public:
    bool issorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (!issorted(nums)) {
            int minsum = INT_MAX;
            int ind = -1;

            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minsum) {
                    minsum = sum;
                    ind = i;
                }
            }

            vector<int> temp;
            for (int i = 0; i < ind; i++) {
                temp.push_back(nums[i]);
            }
            temp.push_back(minsum);
            for (int i = ind + 2; i < nums.size(); i++) {
                temp.push_back(nums[i]);
            }

            nums = temp;
            count++;
        }
        return count;
    }
};