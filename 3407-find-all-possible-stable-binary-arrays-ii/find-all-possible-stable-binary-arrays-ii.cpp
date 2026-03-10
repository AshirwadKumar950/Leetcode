class Solution {
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {
        int MOD = 1e9 + 7;
        int dp[1001][1001][2];

        memset(dp,0,sizeof(dp));


        for(int i = 0; i <= min(zeros,limit); i++){
            dp[i][0][0] = 1;
        }
        for(int j = 0; j <= min(ones,limit); j++){
            dp[0][j][1] = 1;
        }

        for(int i = 1; i <= zeros; i++){
            for(int j = 1; j <= ones; j++){
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;

                if(i - limit - 1 >= 0)
                    dp[i][j][0] = (dp[i][j][0] - dp[i-limit-1][j][1] + MOD) % MOD;

                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;

                if(j - limit - 1 >= 0)
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-limit-1][0] + MOD) % MOD;
            }
        }

        int startWithZero = dp[zeros][ones][false];
        int startWithOne = dp[zeros][ones][true];

        return (startWithZero + startWithOne) % MOD;
    }
};