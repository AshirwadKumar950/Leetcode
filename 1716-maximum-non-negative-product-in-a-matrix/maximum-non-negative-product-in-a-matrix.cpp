class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        ll dp[16][16][2];
        dp[0][0][0] = dp[0][0][1] = grid[0][0];

        for(int i = 1; i < n; i++){
            dp[0][i][0] = dp[0][i-1][0]*grid[0][i];
            dp[0][i][1] = dp[0][i-1][1]*grid[0][i];
        }

        for(int i = 1; i < m; i++){
            dp[i][0][0] = dp[i-1][0][0]*grid[i][0];
            dp[i][0][1] = dp[i-1][0][1]*grid[i][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                ll val = grid[i][j];

                ll topmin = dp[i-1][j][0];
                ll topmax = dp[i-1][j][1];

                ll leftmin = dp[i][j-1][0];
                ll leftmax = dp[i][j-1][1];

                ll a = topmin*val;
                ll b = topmax*val;  
                ll c = leftmin*val;
                ll d = leftmax*val;

                dp[i][j][0] = min({a,b,c,d});
                dp[i][j][1] = max({a,b,c,d});
            }
        }

        ll ans = max(dp[m-1][n-1][0],dp[m-1][n-1][1]);

        return ans < 0 ? -1 : ans%mod;
    }
};