class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n1; i++){
            mp[nums1[i]] = i;
        }
        vector<int>ans(n1,-1);
        stack<int>st;
        for(int i = n2-1; i >= 0; i--){
            int val = nums2[i];
            while(!st.empty() && st.top() < val){
                st.pop();
            }
            if(mp.find(val) != mp.end() && !st.empty()){
                ans[mp[val]] = st.top();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};