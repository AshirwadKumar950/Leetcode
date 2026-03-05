class Solution {
public:
    int minOperations(string s) {
        int l = s.length();
        int c1 = 0, c2 = 0;
        for(int i = 0; i < l; i++){
            int val = s[i];
            if(i%2 == 0){
                if(val == '0') c2++;
                else c1++;
            }else{
                if(val == '1') c2++;
                else c1++;
            }
        }
        return min(c1,c2);
    }
};