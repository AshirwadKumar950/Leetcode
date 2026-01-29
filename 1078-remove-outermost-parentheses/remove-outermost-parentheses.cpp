class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = s.length();
        int c1 = 0, c2 = 0;
        int k = 0;
        unordered_set<int>st;
        for(int i = 0; i < l; i++){
            if(s[i] == '(') c1++;
            if(s[i] == ')') c2++;
            if(c1 != 0 && c1 == c2){
                st.insert(k);
                st.insert(i);
                if(i+1 < l) k = i+1;
                c1 = 0;c2 = 0;
            }
        }
        string ans ="";
        for(int i = 0; i < l; i++){
            if(st.find(i) == st.end()) ans += s[i];
        }
        return ans;
    }
};