class Solution {
public:
    const int mod = 1e9+7;
    int numberOfStableArrays(int zeros, int ones, int limit) {
        int dp[201][201][2][201];
        memset(dp,0,sizeof(dp));
        dp[1][0][0][1] = 1;
        dp[0][1][1][1] = 1;
            for(int x = 0; x <= zeros; x++){
                for(int y = 0; y <= ones; y++){
                    for(int last = 0; last < 2; last++){
                        for(int cons = 1; cons <= limit; cons++){
                            int val = dp[x][y][last][cons];
                            if(val == 0) continue;

                            if(last == 0){

                                if(x+1 <= zeros && cons < limit)
                                    dp[x+1][y][0][cons+1] =
                                    (dp[x+1][y][0][cons+1] + val) % mod;

                                if(y+1 <= ones)
                                    dp[x][y+1][1][1] =
                                    (dp[x][y+1][1][1] + val) % mod;

                            }
                            else{

                                if(y+1 <= ones && cons < limit)
                                    dp[x][y+1][1][cons+1] =
                                    (dp[x][y+1][1][cons+1] + val) % mod;

                                if(x+1 <= zeros)
                                    dp[x+1][y][0][1] =
                                    (dp[x+1][y][0][1] + val) % mod;
                            }
                        }
                    }
                }
            }

        int ans = 0;
        for(int c=1;c<=limit;c++){
            ans = (ans + dp[zeros][ones][0][c]) % mod;
            ans = (ans + dp[zeros][ones][1][c]) % mod;
        }
        return ans;
    }
};
