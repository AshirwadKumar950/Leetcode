class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // given an array of length n
        // q queries where q[i] = [l,r]
        // for each query select a subset of indices in the range [l,r]
        // decrement the values at the selected indices by 1
        // if all can become 0 find out

        int n = nums.size();

        vector<int>diff(n,0);
        for(auto &q : queries){
            int l = q[0], r = q[1];
            diff[l] -= 1;
            if(r+1 < n) diff[r+1] += 1;
        }
        for(int i = 1; i < n; i++){
            diff[i] += diff[i-1];
        }
        // [-1,0,0]
        // [-1,]
        for(int i = 0; i < n; i++){
            if(nums[i] > abs(diff[i])) return false;
        }
        return true;
    }
};