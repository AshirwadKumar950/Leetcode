class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int cnt = 0;
        bool is = false;
        while(n > 0){
            cout<<n%2;
            if(n%2 == 1){
                is = true; 
            }
            if(is) cnt++;
            if(is && n%2 == 1){
                ans = max(ans,cnt-1);
                cnt = 1;
            }
            n /= 2;
        }
        return ans;
    }
};