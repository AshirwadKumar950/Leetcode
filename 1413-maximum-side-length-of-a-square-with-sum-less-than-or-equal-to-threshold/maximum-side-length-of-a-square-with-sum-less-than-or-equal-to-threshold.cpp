class Solution {
public:
    bool check(vector<vector<int>>&mat, vector<vector<int>>& prefix, int mid, int threshold){
        int m = mat.size();
        int n = mat[0].size();

        
        return 0;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        /*
            [1,1,3,2,4,3,2]
            [1,1,3,2,4,3,2]
            [1,1,3,2,4,3,2]

            [1,2,5,7,11,14,16]          [1,2,5,7,11,14,16]
            [1,2,5,7,11,14,16]          [2,4,10,14,22,28,32]
            [1,2,5,7,11,14,16]          []

            sum is stored from (0,0) to (i,j)
        */
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
        // prefix[0][0] = mat[0][0];
        // for(int i = 1; i < n; i++){
        //     prefix[0][i] = mat[0][i] + prefix[0][i-1];
        // }
        // for(int i = 1; i < m; i++){
        //     prefix[i][0] = mat[i][0] + prefix[i-1][0];
        // }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefix[i+1][j+1] = mat[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
            }
        }
        
        int ans = 0;
        auto getSum = [&](int r, int c, int k){
        int r2 = r + k;
        int c2 = c + k;
        return prefix[r2][c2] 
             - prefix[r][c2] 
             - prefix[r2][c] 
             + prefix[r][c];
        };
        for(int k = 1; k <= min(m,n); k++){
            for(int i = 0; i <= m-k; i++){
                for(int j = 0; j <= n-k; j++){
                    int sum = getSum(i,j,k);
                    if(sum <= threshold){
                        ans = max(ans,k);
                        //goto nextsize;
                    }
                }
            }
            //nextsize;
        }
        return ans;
    }   
};