class Solution {
public:
    typedef long long ll;
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll>arr;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                arr.push_back(grid[i][j]);
            }
        }

        int sz = arr.size();
        vector<ll>suffix(sz);
        suffix[sz-1] = 1ll*arr[sz-1];
        for(int i = sz-2; i >= 0; i--){
            suffix[i] = (1ll*arr[i]*suffix[i+1])%mod;
        }
        ll pre = 1;
        vector<int>ans;
        for(int i = 0; i < sz; i++){
            ans.push_back((pre * (i+1 < sz ? suffix[i+1] : 1)) % mod);
            pre = (pre*arr[i])%mod;
        }
        vector<vector<int>>result(m,vector<int>(n));
        int row = 0, col = 0;
        for(int i = 0; i < sz; i++){
            result[row][col] = ans[i];
            col++;
            if(col == n){
                col = 0;
                row++;
            }
        }
        return result;
    }
};