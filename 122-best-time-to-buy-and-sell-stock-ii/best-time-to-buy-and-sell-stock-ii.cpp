class Solution {
public:
    int dp[30001][3];
    int rec(int i, int n, vector<int>&prices, int hold){
        if(i == n) return 0;
        if(dp[i][hold] != -1) return dp[i][hold];
        int nottake = rec(i+1,n,prices,hold);
        int take;
        if(hold == 0){
            take = - prices[i] + rec(i+1,n,prices,1);
        }else{
            take = prices[i] + rec(i+1,n,prices,0);
        }
        return dp[i][hold] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(0,prices.size(),prices,0);
    }
};