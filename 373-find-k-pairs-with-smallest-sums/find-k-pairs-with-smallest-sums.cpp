class Solution {
public:
    typedef pair<int,pair<int,int>> piii;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<piii,vector<piii>,greater<piii>>pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 == 0 || n2 == 0) return {};
        for(int i = 0; i < min(k,n1); i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        } 
        vector<vector<int>>ans;
        while(k--){
            piii tp = pq.top();
            pq.pop();
            int i = tp.second.first, j = tp.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1 < n2){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};