class Solution {
public:
    string removeDuplicateLetters(string s) {
        /*
            every letter appears only once in the string
            all letters in the string are distinct and also
            make the string lexicographically smallest
        */
        int l = s.length();
        vector<int>count(26,0);
        for(auto &ch : s){
            count[ch-'a']++;
        }
        //i got all the elements count
        stack<char>st;
        vector<bool>visited(26,false);
        for(int i = 0; i < l; i++){
            char ch = s[i];
            count[ch-'a']--;
            if(visited[ch-'a']) continue;
            while(!st.empty() && st.top() > ch && count[st.top()-'a'] > 0){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            visited[ch-'a'] = true;
            st.push(ch);
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }
        return ans;
    }
};