class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // number of cons 1's ending at each position

        vector<vector<int>>pre(m,vector<int>(n));
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = m-1; j >= 0; j--){
                if(matrix[j][i] == 1) cnt++;
                else cnt = 0;
                pre[j][i] = cnt;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            sort(pre[i].begin(),pre[i].end());
            for(int j = 0; j < n; j++){
                ans = max(ans,pre[i][j]*(n - j));
            }
        }
        return ans;
    }
};