class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = x,t = x+k-1; i < t; i++,t--){
            for(int j = y; j < y+k; j++){
                swap(grid[i][j],grid[t][j]);
            }
        }
        return grid;
    }
};