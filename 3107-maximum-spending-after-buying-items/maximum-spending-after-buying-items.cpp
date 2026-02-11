class Solution {
public:
    typedef long long ll;
    typedef tuple<int,int,int> tp;
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        priority_queue<tp, vector<tp>, greater<tp>>pq;
        for(int i = 0; i < m; i++){
            pq.push({values[i][n-1],i,n-1});
        }
        ll ans = 0;
        int days = 1;
        while(!pq.empty()){
            auto [a,b,c] = pq.top();
            pq.pop();
            ans += (1ll*a*days);
            days++;
            if(c == 0) continue;
            pq.push(make_tuple(values[b][c-1],b,c-1));
        }
        return ans;
    }
};