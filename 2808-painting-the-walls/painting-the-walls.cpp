class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 1e9;
        vector<vector<int>>dp(n+1,vector<int>(n+1,INF));
        for(int i = 0; i <= n; i++){
            dp[i][n] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            for(int used = 0; used <= n; used++){
                int dont = dp[i+1][used];
                int next = min(n,used+1+time[i]);
                int paint = cost[i] + dp[i+1][next];

                dp[i][used] = min(dont, paint);
            }
        }
        return dp[0][0];
    }
};