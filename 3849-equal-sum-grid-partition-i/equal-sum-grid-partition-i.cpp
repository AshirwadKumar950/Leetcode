class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        ll totalSum = 0;
        vector<ll>rowSum(m,0),colSum(n,0);
        for(int i = 0; i < m; i++){
            ll s1 = 0;
            for(int j = 0; j < n; j++){
                totalSum += grid[i][j];
                s1 += grid[i][j];
            }
            rowSum[i] = s1;
        }

        for(int i = 0; i < n; i++){
            ll s = 0;
            for(int j = 0; j < m; j++){
                s += grid[j][i];
            }
            colSum[i] = s;
        }
        ll sum = 0;
        for(int i = 0; i < m; i++){
            sum += rowSum[i];
            ll left = totalSum - sum;
            if(left == sum ) return true;
        }
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += colSum[i];
            ll left = totalSum - sum;
            if(sum == left) return true;
        }
        return false;
    }
};