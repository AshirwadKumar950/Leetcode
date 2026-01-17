class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        int k = n-1;
        int i = 0, j = n-1;
        while(i <= j){
            int v1 = nums[i]*nums[i];
            int v2 = nums[j]*nums[j];
            if(v1 >= v2){
                result[k--] = v1;
                i++;
            }else{
                result[k--] = v2;
                j--;
            }
        }
        return result;
    }
};