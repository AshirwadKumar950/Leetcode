class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int vowelConsonantScore(string s) {
        int l = s.length();
        int c = 0, v = 0;
        for(auto &ch : s){
            if(isalpha(ch)){
                if(isVowel(ch)){
                    v++;
                }else{
                    c++;
                }
            }
        }
        return c == 0 ? 0 : floor(v/c);
    }
};