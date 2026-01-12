class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        auto last = points[0];
        for(int i = 1; i < n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = last[0], y2 = last[1];

            //to be on same horizontal- y same x different
            //to be on same vertical - x same y different
            //to be on on same diagonal difference raio should be same

            if(y1 == y2){
                result += abs(x1-x2);
            }else if(x1 == x2){
                result += abs(y1-y2);
            }else if(abs(x1-x2) == abs(y1-y2)){
                result += abs(x1-x2);
            }else{
                int diagonal = min(abs(x1-x2),abs(y1-y2));
                int rem = abs(abs(x1-x2)-abs(y1-y2));
                result += diagonal+rem;
            }
            last = points[i];
        }
        return result;
    }
};