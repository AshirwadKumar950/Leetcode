class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 3 == 0) return sum;
        int n = nums.size();
        vector<int>v1,v2;
        for(auto &v : nums){
            if(v%3==1) v1.push_back(v);
            else if(v%3==2) v2.push_back(v);
        }

        
        sort(v1.begin(),v1.end());
        sort(v2.begin(), v2.end());
        int mod = sum%3;
        int ans = 0;
        if(mod == 1){
            if(v1.size() >= 1) ans = max(ans,sum-v1[0]);
            if(v2.size() > 1)  ans = max(ans,sum-v2[0]-v2[1]);
        }else if(mod == 2){
            if(v2.size() >= 1) ans = max(ans,sum-v2[0]);
            if(v1.size() > 1) ans = max(ans,sum-v1[0]-v1[1]);
        }
        return ans;
    }
};