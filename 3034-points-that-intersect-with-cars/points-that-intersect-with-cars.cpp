class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int>st;
        for(auto &q : nums){
            int l = q[0], r = q[1];
            for(int i = l; i <= r; i++) st.insert(i);
        }
        return (int)st.size();
    }
};