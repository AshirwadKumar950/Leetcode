class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                result[i] = nums[i];
            }else if(nums[i] > 0){
                result[i] = nums[(i+nums[i])%n];
            }else{
                int val = abs(nums[i]);
                int j = i;
                while(val){
                    j--;
                    val--;
                    if(j < 0) j = n-1;
                }
                result[i] = nums[j];
            }
        }
        return result;
    }
};