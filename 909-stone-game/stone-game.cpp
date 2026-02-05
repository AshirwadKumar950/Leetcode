class Solution {
public:
    vector<int>piles;

    pair<int,int> rec(int i, int j,int chance, vector<vector<vector<pair<int,int>>>>&dp){
        if(i > j) return {0,0};

        if(dp[i][j][chance] != make_pair(-1,-1)) return dp[i][j][chance];
        if(chance == 0){
            auto left = rec(i+1,j,1,dp);
            auto right = rec(i,j-1,1,dp);
            left.first += piles[i];
            right.first += piles[j];
            return dp[i][j][chance] = (left.first > right.first) ? left : right;
        }else{
            auto left = rec(i+1,j,0,dp);
            auto right = rec(i,j-1,0,dp);
            left.second += piles[i];
            right.second += piles[j];
            return dp[i][j][chance] = (left.second > right.second) ? left : right;
        }
    }

    bool stoneGame(vector<int>& piles) {
       this->piles = piles;
       int n = piles.size();
       vector<vector<vector<pair<int,int>>>>dp(n+1,vector<vector<pair<int,int>>>(n+1,vector<pair<int,int>>(2,{-1,-1})));
       pair<int,int> v = rec(0,n-1,0,dp);
       return v.first > v.second;
    }
};