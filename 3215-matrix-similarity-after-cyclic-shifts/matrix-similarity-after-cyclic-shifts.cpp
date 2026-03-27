class Solution {
public:
    void rightshift(vector<vector<int>>&mat, int row, int k){
        int n = mat[0].size();
        k %= n;
        reverse(mat[row].begin(),mat[row].end());
        reverse(mat[row].begin(),mat[row].begin() + n - k);
        reverse(mat[row].begin()+ n - k, mat[row].end());
    }
    void leftshift(vector<vector<int>>&mat, int row, int k){
        int n = mat[0].size();
        k %= n;
        reverse(mat[row].begin(),mat[row].begin()+k);
        reverse(mat[row].begin()+k,mat[row].end());
        reverse(mat[row].begin(), mat[row].end());
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>original = mat;
       
        for(int i = 0; i < m; i++){
            if(i%2 == 0) leftshift(mat,i,k);
            else rightshift(mat,i,k);
        }
        
        return mat == original;
    }
};