class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p.length();

        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        dp[l1][l2] = true;
        // at l1 
        for(int j = l2-1; j >= 0; j--){
            if(j+1 < l2 && p[j+1] == '*'){
                dp[l1][j] = dp[l1][j+2];
            }
        }
         
        for(int i = l1-1; i >= 0; i--){
            for(int j = l2-1; j >= 0; j--){
                bool match = false;

                if(j+1 < l2 && p[j+1] == '*'){
                    match = dp[i][j+2] || ((s[i] == p[j] || p[j] == '.') && dp[i+1][j]);
                }else if(s[i] == p[j] || p[j] == '.'){
                    match = dp[i+1][j+1];
                }
                dp[i][j] =match;
            }
        }

        return dp[0][0];
    }
};