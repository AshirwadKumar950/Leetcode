class Solution {
public:
    typedef pair<int,int> pii;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>>graph(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,2*w});
        }
        int minCost = 0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,0});
        vector<int>dist(n,1e9+1);
        dist[0] = 0;
        while(!pq.empty()){
            auto [val,node] = pq.top();
            pq.pop();

            if(dist[node] < val) continue;
            for(auto &neigh : graph[node]){
                int nxtNode = neigh.first;
                int wt = neigh.second;
                if(val + wt < dist[nxtNode]){
                    dist[nxtNode] = val + wt;
                    pq.push({val+wt,nxtNode});
                }
            }
        }
        return dist[n-1] == 1e9+1 ? -1 : dist[n-1];
    }
};