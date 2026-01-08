class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int>dp(n2+1,INT_MIN);
        for(int i = 1; i <= n1; i++){
            vector<int>temp(n2+1,INT_MIN);
            for(int j = 1; j <= n2; j++){
                int ans = nums1[i-1]*nums2[j-1];
                int another = dp[j-1];
                if(another != INT_MIN){
                    ans = max(ans,ans+another);
                }
                ans = max(ans,max(temp[j-1],dp[j]));
                temp[j] = ans;
            }
            dp = temp;
        }
        
        return dp[n2];
    }
};