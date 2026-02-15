class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int c1,c2,c3,c4;
        c1=c2=c3=c4=0;
        int ans = INT_MAX;
        for(auto &ch : s){
            if(ch == 'Q') c1++;
            else if(ch == 'W') c2++;
            else if(ch == 'E') c3++;
            else c4++;
        }
        if(c1 == n/4 && c2 == n/4 && c3 == n/4 && c4 == n/4) return 0;
        // i need to find the smallest substring such that
        // i can replace that with my required characters 
        // which makes my string balanced
        int rc1,rc2,rc3,rc4;
        rc1=rc2=rc3=rc4=0;

        rc1 = max(0,c1-n/4);
        rc2 = max(0,c2-n/4);
        rc3 = max(0,c3-n/4);
        rc4 = max(0,c4-n/4);

        int wc1, wc2, wc3, wc4;
        wc1 = wc2 = wc3 = wc4 = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(s[r] == 'Q') wc1++;
            else if(s[r] == 'W') wc2++;
            else if(s[r] == 'E') wc3++;
            else wc4++;

            while(wc1 >= rc1 && wc2 >= rc2 && wc3 >= rc3 && wc4 >= rc4){
                ans = min(ans,r-l+1);
                if(s[l] == 'Q') wc1--;
                else if(s[l] == 'W') wc2--;
                else if(s[l] == 'E') wc3--;
                else wc4--;
                l++;
            }
        }
        return ans;
    }
};