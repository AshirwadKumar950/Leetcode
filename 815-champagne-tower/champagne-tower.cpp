class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>tower(101,vector<double>(101,0.000));

        tower[0][0] = poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                if(tower[i][j] > 1.0){
                    double rest = (tower[i][j] - 1.000)/2.000;
                    tower[i][j] = 1;
                    tower[i+1][j] += rest;
                    tower[i+1][j+1] += rest;
                }
            }
        }
        return min(1.0,tower[query_row][query_glass]);
    }
};