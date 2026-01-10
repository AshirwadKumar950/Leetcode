class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int ans = 0;
        for(auto &ch : s1){
            ans += ch;
        }
        for(auto &ch : s2){
            ans += ch;
        }
        int l1 = s1.length(), l2 = s2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return ans - 2*dp[l1][l2];
    }
};