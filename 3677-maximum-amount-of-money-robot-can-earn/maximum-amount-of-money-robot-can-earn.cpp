class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,-1)));

        for(int i = 0; i <= 2; i++){
            if(coins[m-1][n-1] < 0 && i > 0) dp[m-1][n-1][i] = 0;
            else dp[m-1][n-1][i] = coins[m-1][n-1];
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) continue;
                for(int neutralizations = 0; neutralizations <= 2; neutralizations++){
                    int down = -1e8;
                    if(i+1 < m){
                        if(coins[i][j] >= 0) down = coins[i][j] + dp[i+1][j][neutralizations];
                        else{
                            if(neutralizations > 0){
                                down = max(dp[i+1][j][neutralizations-1], coins[i][j] + dp[i+1][j][neutralizations]);
                            }else down = coins[i][j] +  dp[i+1][j][neutralizations];
                        }
                    }
                    int right = -1e8;
                    if(j+1 < n){
                        if(coins[i][j] >= 0) right = coins[i][j] + dp[i][j+1][neutralizations];
                        else{
                            if(neutralizations > 0){
                                right = max(0 + dp[i][j+1][neutralizations-1], coins[i][j] + dp[i][j+1][neutralizations]);
                            }else right = coins[i][j] + dp[i][j+1][neutralizations];
                        }
                    }
                    dp[i][j][neutralizations] = max(down,right);
                }
            }
        }
        return dp[0][0][2];
    }
};