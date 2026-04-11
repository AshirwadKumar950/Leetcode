class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<deque<int>>arr(n+1);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            arr[nums[i]].push_back(i);
            if(arr[nums[i]].size() == 3){
                int v1 = arr[nums[i]][0], v3 = arr[nums[i]][2];
                int value = 2*(v3-v1);
                ans = min(ans,value);
                arr[nums[i]].pop_front();
            }
        }
       
        return ans == INT_MAX ? -1 : ans;
    }
};