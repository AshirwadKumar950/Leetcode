class Solution {
public:
    int dp[2501][2501];
    int rec(int i, int n, vector<int>&nums, int prev){
        if(i == n) return 0;
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int nottake = rec(i+1,n,nums,prev);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1+rec(i+1,n,nums,i);
        }
        if(prev == -1) return max(take,nottake);
        else
        return dp[i][prev] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        //till index i longest increasing subsequence
        //and till that index what is the largest last element
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n,nums,-1);
    }
};