class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &ch : s){
            if(!st.empty()){
                char c = st.top();
                if((c == '(' && ch == ')') || (c == '{' && ch == '}') || (c == '[' && ch == ']')){
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.empty();
    }
};