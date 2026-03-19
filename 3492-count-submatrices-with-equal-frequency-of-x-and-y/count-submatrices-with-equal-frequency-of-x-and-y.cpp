class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>x(n,0),y(n,0);
        int ans = 0;
        for(int i = 0; i < m; i++){
            int xc = 0, yc = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X') x[j]++;
                if(grid[i][j] == 'Y') y[j]++;
                xc += x[j];
                yc += y[j];
                if(xc == yc && xc > 0) ans++;
            }
        }
        return ans;
    }
};