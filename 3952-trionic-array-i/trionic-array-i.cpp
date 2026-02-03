class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n-1 && nums[i] < nums[i+1]) i++;
        if(i == 0 || i == n-1) return false;
        int j = i;
        while(i < n-1 && nums[i] > nums[i+1]) i++;

        if(i == j || i == n-1) return false;

        int k = i;
        while(i < n-1 && nums[i] < nums[i+1]) i++;

        if(i == k) return false;
        return i == n-1;
    }
};