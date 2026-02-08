class Solution {
public:
    typedef long long ll;
    vector<int>nums1,nums2;
    int n ,m, k;
    const ll neg = -2e18;
    ll dp[101][101][101];
    ll rec(int i, int j, int c){
        if(c == k) return 0;
        if(i == n || j == m) return neg;
        ll &ans = dp[i][j][c];
        if(ans != LLONG_MIN) return ans;

        ll s1 = rec(i,j+1,c);
        ll s2 = rec(i+1,j,c);
        ll take = rec(i+1,j+1,c+1);
        if(take != neg){
            take += 1ll*nums1[i]*nums2[j];
        }
        return ans = max({s1,s2,take});
    } 
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->n = nums1.size();
        this->m = nums2.size();
        this->k = k;

        for(int i = 0; i <= 100; i++)
            for(int j = 0; j <= 100; j++)
                for(int k = 0; k <= 100; k++)
                    dp[i][j][k] = LLONG_MIN;
        return rec(0,0,0);
    }
};