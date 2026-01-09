class Solution {
public:
    //the robber needs to steel from atleast k houses
    bool check(vector<int>&nums, int k, int mid){
        //now i need to check if i can steel 
        //at least k non-consecutive houses 
        //with atleast mid value
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] <= mid){
                k--;
                i += 2;
            }else{
                i++;
            }
        }
        return k <= 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int lb = 1, ub = 1e9+1;
        int ans = 0;
        while(lb <= ub){
            int mid = lb + (ub-lb)/2;
            if(check(nums,k,mid)){
                ans = mid;
                ub = mid - 1;
            }else{
                lb = mid + 1;
            }
        }
        return ans;
    }
};