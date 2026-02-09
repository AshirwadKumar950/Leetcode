class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int x = 0;
        int i = 0;
        while(i < n){
            char curr = chars[i];

            int c = 0;
            int j = i;
            while(j < n && chars[j] == curr){
                c++;
                j++;
            }
            chars[x++] = curr;
            if(c == 1) {
                i = j;
                continue;
            }
            string st = to_string(c);
            for(auto &ch : st){
                chars[x++] = ch;
            }
            i = j;
        }
        return x;
    }
};