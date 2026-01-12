class Solution {
public:
    vector<int>subset;
    int n,k;
    int target;
    int rec(int i,vector<int>& nums){
        if(i == n){
            return true;
        }

        for(int j = 0; j < k; j++){
            if(subset[j] + nums[i] > target) continue;
            subset[j] += nums[i];
            if(rec(i+1,nums)) return true;
            subset[j] -= nums[i];
            if(subset[j] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        n = nums.size();
        this->k = k;
        int total = 0;
        for(auto &num : nums){
            total += num;
        }
        if(total % k) return false;
        target = total/k;
        subset.resize(k,0);
       return rec(0,nums);
    }
};