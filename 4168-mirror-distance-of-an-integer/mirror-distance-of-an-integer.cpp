class Solution {
public:
    int mirrorDistance(int n) {
        long long t = n;
        long long sum = 0;
        while(t > 0){
            sum = sum*10 + t%10;
            t/=10;
        }
        return abs(n-sum);
    }
};