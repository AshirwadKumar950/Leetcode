class Solution {
public:
    vector<int>prices;
    int n;
    int dp[5001][2];
    int rec(int i,int hold){
        if(i >= n) return 0;

        if(dp[i][hold] != -1) return dp[i][hold];
        int nottake = rec(i+1, hold);
        int buy;
        if(hold == 0){
            buy = -prices[i]+rec(i+1,1);
        }else{
            buy = prices[i]+rec(i+2,0);
        }
        return dp[i][hold] = max(nottake,buy);
    }
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};