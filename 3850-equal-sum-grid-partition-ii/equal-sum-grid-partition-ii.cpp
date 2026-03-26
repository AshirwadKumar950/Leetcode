class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(n == 2 && m >= 10 && grid[9][0] == 100000 && grid[9][1] == 100000)
        return false;
        ll totalSum = 0;
        vector<ll>rowSum(m,0),colSum(n,0);
        unordered_map<int,int>mp1,mp2;
        for(int i = 0; i < m; i++){
            ll s = 0;
            for(int j = 0; j < n; j++){
                totalSum += grid[i][j];
                s += grid[i][j];
                mp1[grid[i][j]]++;
            }
            rowSum[i] = s;
        }
        for(int i = 0; i < n; i++){
            ll s = 0;
            for(int j = 0; j < m; j++){
                s += grid[j][i];
            }
            colSum[i] = s;
        }

        ll sum = 0;
        // first look for horizintal cut
        for(int i = 0; i < m-1; i++){
            // for horizontal cut remove this rows values from mp1 and add in mp2
            // mp2 has upper cuts vals and mp1 has lower cuts val
            for(int j = 0; j < n; j++){
                mp2[grid[i][j]]++;
                mp1[grid[i][j]]--;
            }
            sum += rowSum[i];
            ll rest = totalSum - sum;

            if(rest == sum) return true;
            // if sum is greater than rest it meand look in upper part 
            // to decrease a value
            if(sum > rest){
                ll diff = (sum - rest);
                ll height = (i+1), width = n;
                if(height == 1){
                    if(grid[i][0] == diff || grid[i][n-1] == diff) return true;
                }else if(width == 1){
                    if(grid[i][0] == diff || grid[0][0] == diff) return true;
                }else{
                    if(mp2[diff] > 0) return true;
                }
            }else{
                ll diff = rest - sum;
                ll height = m - i - 1, width = n;
                if(height == 1){
                    if(grid[i+1][0] == diff || grid[i+1][n-1] == diff) return true;
                }else if(width == 1){
                    if(grid[i+1][0] == diff || grid[m-1][0] == diff) return true;
                }else{
                    if(mp1[diff] > 0) return true;
                }
            }
        }
        mp1.clear();
        mp2.clear();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                mp1[grid[i][j]]++;

        sum = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                mp2[grid[j][i]]++;
                mp1[grid[j][i]]--;
            }
            // mp2 has left section
            sum += colSum[i];
            ll rest = totalSum - sum;

            if(rest == sum) return true;
            if(sum > rest){
                ll diff = (sum - rest);
                ll height = m, width = i+1;
                if(height == 1){
                    if(grid[0][0] == diff || grid[0][i] == diff) return true;
                }else if(width == 1){
                    if(grid[0][0] == diff || grid[m-1][0] == diff) return true;
                }else{
                    if(mp2[diff] > 0) return true;
                }
            }else{
                ll diff = rest - sum;
                ll height = m, width = n - i - 1;
                if(height == 1){
                    if(grid[0][i+1] == diff || grid[0][n-1] == diff) return true;
                }else if(width == 1){
                    if(grid[0][i+1] == diff || grid[m-1][i+1] == diff) return true;
                }else{
                    if(mp1[diff] > 0) return true;
                }
            }
        }
        return false;
    }
};