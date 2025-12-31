class Solution {
public:
    vector<pair<int,int>>direction = {{0,1},{1,0},{0,-1},{-1,0}};
    bool check(int row, int col, vector<vector<int>>&cells,int mid){
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i = 0; i <= mid; i++){
            int r = cells[i][0]-1, c = cells[i][1]-1;
            grid[r][c] = 1;
        }
        queue<pair<int,int>>q;
        for(int i = 0; i < col; i++){
            if(grid[0][i] == 0) q.push({0,i});
        }
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(x == row-1) return true;
            for(auto &dir : direction){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] == 1) continue;
                q.push({nx,ny});
                grid[nx][ny] = 1;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int lb = 0, ub = n-1;
        int ans = 0;
        while(lb <= ub){
            int mid = lb + (ub-lb)/2;
            if(check(row,col,cells,mid)){
                ans = mid + 1;
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        return ans;
    }
};