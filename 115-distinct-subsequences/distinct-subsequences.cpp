class Solution {
public:
typedef long long ll;
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        vector<int>dp(l2+1,0);

        dp[0] = 1;

        for(int i = 1; i <= l1; i++){
            vector<int>temp(l2+1,0);
            temp[0] = 1;
            for(int j = 1; j <= l2; j++){
                ll ways = dp[j];
                if(s[i-1] == t[j-1]){
                    ways += dp[j-1];
                }
                temp[j] = ways;
            }
            dp = temp;
        }
        return dp[l2];
    }
};