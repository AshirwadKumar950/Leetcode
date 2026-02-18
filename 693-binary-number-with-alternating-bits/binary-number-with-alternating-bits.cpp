class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while(n > 0){
            s += (n%2)+'0';
            n /= 2;
        }
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1]) return 0;
        }
        return 1;
    }
};