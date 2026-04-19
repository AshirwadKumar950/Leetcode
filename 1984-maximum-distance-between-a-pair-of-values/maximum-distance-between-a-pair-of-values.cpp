class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        /*
            for each i in nums[i] search for rightmost
            value which is >= nums1[i] segment tree is one
        */
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;
        for(int i = 0; i < n1; i++){
            int lb = i, ub = n2-1;
            if(ub < lb) continue;
            int val = nums1[i];
            int idx = i;
            while(lb <= ub){
                int mid = (lb + ub)/2;
                if(nums2[mid] >= val){
                    idx = mid;
                    lb = mid + 1;
                }else ub = mid - 1;
            }
            ans = max(ans,idx-i);
        }
        return ans;
    }
};