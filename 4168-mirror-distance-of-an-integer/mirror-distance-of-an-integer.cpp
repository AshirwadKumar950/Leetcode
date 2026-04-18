class Solution {
public:
    typedef long long ll;
    int mirrorDistance(int n) {
        ll t = n;
        ll sum = 0;
        while(t > 0){
            sum = sum*10 + t%10;
            t/=10;
        }
        return abs(n-sum);
    }
};