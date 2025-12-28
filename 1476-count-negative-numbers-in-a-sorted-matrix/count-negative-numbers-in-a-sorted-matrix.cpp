class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int count = 0;
        for(int i = 0; i < m; i++){
            int lb = 0;
            int ub = grid[i].size() - 1;
            int ans = -1;
            while( lb <= ub){
                int mid = lb + (ub - lb) / 2;
                if(grid[i][mid] < 0){
                    ans = mid;
                    ub = mid - 1;
                }else{
                    lb = mid + 1;
                }
            }
            if(ans != -1){
                count += (grid[i].size() - ans );
            }
        }
        return count;
    }
};