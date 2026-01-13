class Solution {
public:
    pair<double,double>get(vector<vector<int>>&squares, double mid){
        double downArea = 0, upArea = 0;
        for(auto &square : squares){
            double x = square[0], y = square[1], l = square[2];

            if(y + l <= mid){
                downArea += l*l;
            }else if(y >= mid){
                upArea += l*l;
            }else{
                double downLength = mid - y;
                double upLength = (y+l)-mid;
                downArea += downLength*l;
                upArea += upLength*l;
            }
        }
        return {upArea,downArea};
    }
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double lb = 1e18, ub = -1e18;
        for(auto &square : squares){
            lb = min(lb,(double)square[1]);
            ub = max(ub,(double)square[1]+square[2]);
        }
        while(ub - lb >= 1e-5){
            //mid is the mid line where i will check
            //area at top of this and area at bottom of this
            double mid = lb + (ub-lb)/2;
            auto [up,down] = get(squares,mid);
            if(up > down){
                lb = mid;
            }else{
                ub = mid;
            }
        }
        return lb;
    }
};