class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;
        int c = 1;
        int x = 0;
        for(int i = 1; i < n; i++){
            if(chars[i] == chars[i-1]){
                c++;
            }else{
                chars[x++] = chars[i-1];
                if(c > 1){
                    string st = to_string(c);
                    for(auto &ch : st){
                        chars[x++] = ch;
                    }
                }
                c = 1;
            }
        }
        chars[x++] = chars[n-1];
        if(c > 1){
            string st = to_string(c);
            for(auto &ch : st){
                chars[x++] = ch;
            }
        }
        return x;
    }
};