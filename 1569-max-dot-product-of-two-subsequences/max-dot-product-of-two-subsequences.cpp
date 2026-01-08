class Solution {
public:
    // int rec(int i, int j){
    //     if(i == n1 || j == n2) return INT_MIN;

    //     if(dp[i][j] != INT_MIN) return dp[i][j];
    //     int ans = nums1[i]*nums2[j];
    //     int another = rec(i+1,j+1);
    //     if(another!=INT_MIN){
    //         ans = max(ans,ans+another);
    //     }
    //     ans = max(ans, max(rec(i+1,j),rec(i,j+1)));
    //     return dp[i][j] = ans;
    // }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //dp[i][j] will be the maximum product of subsequence 
        //of nums1 and nums2 starting with position i int nums1
        //ans j in nums2
        int dp[501][501];
        for(int i = 0; i <= 500; i++)
            for(int j = 0; j <= 500; j++)
                dp[i][j] = INT_MIN;

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                int ans = nums1[i-1]*nums2[j-1];
                int another = dp[i-1][j-1];

                if(another != INT_MIN)
                ans = max(ans,ans+another);
                ans = max(ans,max(dp[i-1][j],dp[i][j-1]));
                dp[i][j] = ans;
            }
        }
        return dp[n1][n2];
    }
};