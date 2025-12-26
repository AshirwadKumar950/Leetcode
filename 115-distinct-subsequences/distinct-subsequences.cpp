class Solution {
public:
    string s,t;
    int l1,l2;
    int dp[1001][1001];
    int rec(int i, int j){
        if(j == l2) return 1;

        if(i == l1){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ways = rec(i+1,j);
        if(s[i] == t[j]){
            ways += rec(i+1,j+1);
        }
        return dp[i][j] = ways;
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        this->l1 = s.length();
        this->l2 = t.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};