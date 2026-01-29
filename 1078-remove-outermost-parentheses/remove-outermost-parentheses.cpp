class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = s.length();
        int c1 = 0;
        string ans ="";
        for(int i = 0; i < l; i++){
            if(s[i] == '('){
                if(c1 > 0) ans += s[i];
                c1++;
            }else{
                c1--;
                if(c1 > 0) ans += s[i];
            }
        }
        return ans;
    }
};