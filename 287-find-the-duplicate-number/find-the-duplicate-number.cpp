class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool>found(n,false);
        for(auto num : nums){
            if(found[num]) return num;
            found[num] = true;
        }
        return n;
    }
};