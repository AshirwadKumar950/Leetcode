class Solution {
public:
    int minFlips(string s) {
        /*
            111000
            i can make this two things
            010101 or 101010

            for each position i can flip it if its not at right pos
            111000111000

            101010111000
        */
        int n = s.length();
        s += s;
        int l = s.length();
        unordered_set<int>st;
        int c1 = 0,c2 = 0;
        int l1 = 0;
        int ans = INT_MAX;
        for(int i = 0; i < l; i++){
            if(i - l1 + 1 > n){
                if(l1%2 == 0){
                    if(s[l1] == '0'){
                        c1--;
                    }else{
                        c2--;
                    }
                }else{
                    if(s[l1] == '1') c1--;
                    else c2--;
                }
                l1++;
            }
            if(i%2 == 0){
                if(s[i] == '0') c1++;
                if(s[i] == '1') c2++;
            } else{
                if(s[i] == '1') c1++;
                if(s[i] == '0') c2++;
            }
            if(i - l1 +1 == n) ans = min({ans,c1,c2});
        }
        return ans;
    }
};