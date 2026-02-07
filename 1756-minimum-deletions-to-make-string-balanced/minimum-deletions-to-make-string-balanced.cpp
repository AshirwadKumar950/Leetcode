class Solution {
public:
    int minimumDeletions(string s) {
        //aabaaaaa
        //aabbbbbaaaaaaaaaabbaa
        //aabbbbbbaaa
        int n = s.length();
        int res = 0, c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b') c++;
            if(s[i] == 'a'){
                if(c > 0){
                    res++;
                    c--;
                }
            }
        }
        return res;
    }
};