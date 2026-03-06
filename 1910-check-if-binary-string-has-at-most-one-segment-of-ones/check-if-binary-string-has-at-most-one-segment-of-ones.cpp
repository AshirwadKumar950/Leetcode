class Solution {
public:
    bool checkOnesSegment(string s) {
        int l = s.length();
        int c = 0;
        bool one = false;
        for(int i = 0; i < l; i++){
            if(s[i] == '1'){
                c++;
            }else if(one && c > 0) return false;
            else{
                one = true;
                c = 0;
            }
        }
        if(one && c > 0) return false;
        return true;
    }
};