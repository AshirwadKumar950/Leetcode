class Solution {
public:
typedef long long ll;
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        int dp[1001][1001];
        memset(dp,0,sizeof(dp));

        for(int i = 0; i <= l1; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                ll ways = dp[i-1][j];
                if(s[i-1] == t[j-1]){
                    ways += dp[i-1][j-1];
                }
                dp[i][j] = ways;
            }
        }
        return dp[l1][l2];
    }
};