class Solution {
public:
    bool judgeCircle(string moves) {
        int l = 0, u = 0;
        for(auto &c : moves){
            if(c == 'L' || c == 'R') l += (c == 'L' ? 1 : -1);
            else u += (c == 'U' ? 1 : -1);
        }
        return l == 0 && u == 0;
    }
};