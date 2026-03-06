class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int>st(n+2,0);
            int cnt = 0;
            int tc = 0;
            for(int j = i; j < n; j++){
                if(st[nums[j]] != 0) {
                    ans += cnt;
                    continue;//if in set continue
                }
                st[nums[j]]++;     // insert in set now look for 1 smaller or one larger it cant be in a pair
                tc++;
                if((st[nums[j]-1] == 0) && (st[nums[j]+1] == 0) && tc > 1){
                    cnt++;
                }
                if((st[nums[j]-1] != 0) && (st[nums[j]+1] != 0)) cnt--;
                ans += cnt;
            }
        }
        return ans;
    }
};