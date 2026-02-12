class Solution {
public:
    int longestBalanced(string s) {
       int ans = 0;
        int len = s.length();
        for(int r = 0; r < len; r++){
           unordered_map<int,int>freq;
            for(int l = r; l < len; l++){
                freq[s[l]-'a']++;
                int val = -1;
                bool is = true;
                for(auto [k,v] : freq){
                    if(val == -1) val = v;
                    else if(v != val){
                        is = false;break;
                    }
                }
                if(is) ans = max(ans,l-r+1);
            }
        }
        return ans;
    }
};