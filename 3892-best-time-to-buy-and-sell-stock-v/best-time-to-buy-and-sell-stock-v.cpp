class Solution {
public:
typedef long long ll;
    ll dp [1001][501][3];
    ll rec(int i, int t, int st, vector<int>&prices, int n, int k){
        if(i == n){
            return (st == 0 ? 0 : LLONG_MIN / 2 );
        }
        if(dp[i][t][st] != -1) return dp[i][t][st];
        ll ans = rec(i+1,t,st,prices,n,k);
        if(st == 0){
            ans = max(ans, rec(i+1,t,1,prices,n,k) - prices[i]);
            ans = max(ans, rec(i+1,t,2,prices,n,k) + prices[i]);
        }else if(st == 1 && t < k){
            ans = max(ans, rec(i+1,t+1,0,prices,n,k) + prices[i]);
        }else if(st == 2 && t < k){
            ans = max(ans, rec(i+1,t+1,0,prices,n,k) - prices[i]);
        }

        return dp[i][t][st] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));

        return rec(0,0,0,prices,prices.size(),k);
    }
};