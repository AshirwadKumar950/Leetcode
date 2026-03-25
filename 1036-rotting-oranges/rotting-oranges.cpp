class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int countFresh = 0;
        int countRotten = 0;
        queue<pair<int,int>>q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) countFresh++;
                else if(grid[i][j] == 2) {
                    countRotten++;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            bool rottenthisround = false;
            while(size--)
            {
                auto [a,b] = q.front();
                q.pop();
                for(auto pair : dir){
                    int x = a + pair.first;
                    int y = b + pair.second;
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    if(grid[x][y] == 1){
                        countFresh--;
                        rottenthisround = true;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            if(rottenthisround)
            time++;
        }
        if(countFresh == 0) return time;
        return -1;
    }
};