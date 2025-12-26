class Solution {
public:
    string s1,s2,s3;
    int l1,l2,l3;
    int dp[101][101];
    bool rec(int i, int j){
        if(i == l1 && j == l2) return true;
        int k = i+j;
        if(dp[i][j] != -1) return dp[i][j];
        //compare s3 with s1
        bool take = false;
        if(i < l1 && s3[k] == s1[i]){
            take = take || rec(i+1,j);
        }
        //compare s3 with s2
        if(j < l2 && s3[k] == s2[j]){
            take = take || rec(i,j+1);
        }
        return dp[i][j] = take;
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;  
        memset(dp,-1,sizeof(dp));

        this->l1 = s1.length();
        this->l2 = s2.length();
        this->l3 = s3.length();
        if(l1 + l2 != l3) return false; 
        return this->rec(0,0);
    }
};