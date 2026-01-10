class Solution {
public:
    typedef pair<int,pair<int,int>> piii;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<piii,vector<piii>,greater<piii>>pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i < min(1000,n1); i++){
            for(int j = 0; j < min(1000,n2); j++){
                pq.push({nums1[i]+nums2[j],{i,j}});
            }
        } 
        vector<vector<int>>ans;
        while(k--){
            piii tp = pq.top();
            pq.pop();
            ans.push_back({nums1[tp.second.first],nums2[tp.second.second]});
        }
        return ans;
    }
};