class Solution {
public:
    typedef long long ll;
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll maxArea = 0;
        int n = bottomLeft.size();
        for(int i = 0; i < n; i++){
            int bx1 = bottomLeft[i][0], by1 = bottomLeft[i][1];
            int tx1 = topRight[i][0], ty1 = topRight[i][1];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int bx2 = bottomLeft[j][0], by2 = bottomLeft[j][1];
                int tx2 = topRight[j][0], ty2 = topRight[j][1]; 

                int x_overlap = min(tx1,tx2) - max(bx1,bx2);
                int y_overlap = min(ty1,ty2) - max(by1,by2);
                if(x_overlap <= 0 || y_overlap <= 0) continue;
                int val = min(x_overlap,y_overlap);
                ll overlappingArea = 1ll*val*val;
                maxArea = max(maxArea,overlappingArea);
            }
        }
        return maxArea;
    }
};