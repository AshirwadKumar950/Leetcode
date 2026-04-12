class Solution {
public:
    int getDist(int c1, char c2){
        int v1 = c1;
        int v2 = c2 - 'A';
        int r1 = v1/6;
        int r2 = v2/6;
        int m1 = v1%6;
        int m2 = v2%6;
        int dist = abs(r1-r2) + abs(m1-m2);
        return dist;
    }
    int dp[301][27][27];
    int rec(int i, string& word, int l, int r){
        if(i == word.length()) return 0;

        if(dp[i][l+1][r+1] != -1) return dp[i][l+1][r+1];
        // this word i can choose to type this from
        // left or right
        int o1 = 0, o2 = 0;
        if(l == -1){
            o1 += rec(i+1,word,word[i]-'A',r);
        }else{
            o1 += getDist(l,word[i]) + rec(i+1,word,word[i]-'A',r);
        }

        if(r == -1){
            o2 += rec(i+1,word,l,word[i]-'A');
        }else{
            o2 += getDist(r,word[i]) + rec(i+1,word,l,word[i]-'A');
        }
        return dp[i][l+1][r+1] = min(o1,o2);
    }
    int minimumDistance(string word) {
        // "HAPPY"
        // for this cahracter my one of the two finger can
        // be here if it is here for next i can use this or last one
        // for the given letter we can get it's coordinate
        memset(dp,-1,sizeof(dp));
        return rec(0,word,-1,-1);
    }
};