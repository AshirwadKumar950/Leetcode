class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        //i am going to generate all kinds of k*k matrix
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,0));
        vector<vector<vector<int>>>allmat;
        for(int i = 0; i <=m-k; i++){
            for(int j = 0; j <=n-k; j++){
                unordered_set<int> dist;
                for(int x = i; x < i+k; x++){
                    for(int y = j; y < j+k; y++){
                        dist.insert(grid[x][y]);
                    }
                }
                int minval = INT_MAX;
                if(dist.size() <= 1){
                    ans[i][j] = 0;
                }else{
                    vector<int>vals(dist.begin(),dist.end());
                    sort(vals.begin(),vals.end());
                    int mindiff = INT_MAX;
                    for (int z = 1; z < vals.size(); z++) {
                        mindiff = min(mindiff,vals[z]-vals[z-1]);
                    }
                    ans[i][j] = mindiff;
                }
            }
        }
        return ans;
    }
};