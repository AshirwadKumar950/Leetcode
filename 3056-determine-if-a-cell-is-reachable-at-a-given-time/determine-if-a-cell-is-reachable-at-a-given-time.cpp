class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // find minimum moves to reach that cell if can yes or no
        if(sx == fx && sy == fy){
            if(t == 1) return false;
            return true;
        }
        
        int time = max(abs(sx-fx),abs(sy-fy));

        return time <= t;
    }
};