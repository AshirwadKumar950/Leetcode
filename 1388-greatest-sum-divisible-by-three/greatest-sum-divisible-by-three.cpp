class Solution {
public:
    vector<int>nums;
    int n;
    int dp[100001][4];
    int rec(int i, int mod){
        if(i == n){
            if(mod == 0) return 0;
            return INT_MIN;
        }
        if(dp[i][mod] != -1) return dp[i][mod];
        int notcon = rec(i+1,mod);
        int cons = nums[i] + rec(i+1,(mod+nums[i])%3);
        return dp[i][mod] = max(notcon,cons);
    }
    int maxSumDivThree(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};