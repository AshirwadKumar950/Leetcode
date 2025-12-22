class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        // for(auto &e : envelopes)
        //     cout<<"["<<e[0]<<","<<e[1]<<"]"<<" ";

        vector<int>tails;
        for(auto &en : envelopes){
            auto it = lower_bound(tails.begin(),tails.end(),en[1]);
            if(it == tails.end()){
                tails.push_back(en[1]);
            }else{
                *it = en[1];
            }
        }
        return tails.size();
    }
};