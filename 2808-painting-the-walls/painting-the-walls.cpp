class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 1e9;
        vector<int>dp(n+1,INF);
        for(int i = 0; i <= n; i++){
            dp[n] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            vector<int>curr(n+1,INF);
            for(int used = 0; used <= n; used++){
                int dont = dp[used];
                int next = min(n,used+1+time[i]);
                int paint = cost[i] + dp[next];

                curr[used] = min(dont, paint);
            }
            dp = curr;
        }
        return dp[0];
    }
};