class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int>dp = grid[0];
        for(int i = 1; i < n; i++){
            int s = INT_MAX, sec = INT_MAX;
            int idx = -1;
            for(int j = 0; j < n; j++){
                if(dp[j] < s){
                    sec = s;
                    s = dp[j];
                    idx = j;
                }else if(dp[j] < sec){
                    sec = dp[j];
                }
            }

            vector<int>newdp(n,0);
            for(int j = 0; j < n; j++){
                newdp[j] = min(1ll*INT_MAX,1ll*grid[i][j] + 1ll*(j == idx ? sec : s));
            }
            dp = newdp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};