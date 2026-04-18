class Solution {
public:
    int dp[21][21];
    bool rec(int i, int j, int l1, int l2, string& s, string& p){
        if(j == l2) return i == l1;

        if(i == l1){
            if(j+1 < l2 && p[j+1] == '*')
                return rec(i,j+2,l1,l2,s,p);
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool matched = false;
        if(j+1 < l2 && p[j+1] == '*'){
            matched = rec(i,j+2,l1,l2,s,p) || ((p[j] == '.' || s[i] == p[j]) && rec(i+1,j,l1,l2,s,p));
        }else if(s[i] == p[j] || p[j] == '.'){
            matched = rec(i+1,j+1,l1,l2,s,p);
        }
        return dp[i][j] = matched;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s.length(),p.length(),s,p);
    }
};