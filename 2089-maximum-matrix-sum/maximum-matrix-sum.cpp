class Solution {
public:
typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0;
        int cneg = 0;
        int sma = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        bool f = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < 0)
                cneg++;

                sma = min(sma,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                if(matrix[i][j] == 0) f = true;
            }
        }
        if(cneg % 2 == 0) return sum;
        if(f) return sum;
        return sum - 2*abs(sma);
    }
};