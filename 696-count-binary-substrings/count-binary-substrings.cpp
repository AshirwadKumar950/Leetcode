class Solution {
public:
    int countBinarySubstrings(string s) {
        int l = s.length();
        int cnt = 0;
        int prev = 0;
        bool is = false;
        int ans = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == '0' && !is){
                cnt++;
            }else if(s[i] == '1' && is){
                cnt++;
            }else{
                ans += min(prev,cnt);
                prev = cnt;
                cnt = 1;
                is = !is;
            }
        }
        ans += min(prev,cnt);
        return ans;
    }
};