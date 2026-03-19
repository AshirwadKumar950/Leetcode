class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // keep the count of X and Y till index i and j
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>xcount(m,vector<int>(n,0));
        vector<vector<int>>ycount(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X') xcount[i][j] = 1;
                if(grid[i][j] == 'Y') ycount[i][j] = 1;
            }
        }
        for(int i = 1; i < n; i++){
            xcount[0][i] += xcount[0][i-1];
            ycount[0][i] += ycount[0][i-1];
        }
        for(int i = 1; i < m; i++){
            xcount[i][0] += xcount[i-1][0];
            ycount[i][0] += ycount[i-1][0];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                xcount[i][j] += xcount[i-1][j] + xcount[i][j-1] - xcount[i-1][j-1];
                ycount[i][j] += ycount[i-1][j] + ycount[i][j-1] - ycount[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(xcount[i][j] == ycount[i][j] && xcount[i][j] != 0) ans++;
            }
        }
        return ans;
    }
};