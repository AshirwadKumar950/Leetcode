class Solution {
public:
    int dp[1001][1001];
    vector<vector<pair<int,int>>>graph;
    vector<int>fee;
    int n;
    int rec(int node, int time, int maxTime){
        if(time > maxTime) return INT_MAX;
        if(node == n-1) return fee[node];
        
        if(dp[node][time] != -1) return dp[node][time];
        int cost = INT_MAX;
        for(auto &neigh : graph[node]){
            int ct = rec(neigh.first,time+neigh.second, maxTime);
            if(ct != INT_MAX){
                cost = min(cost, ct + fee[node]);
            }
        }
        return dp[node][time] = cost;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size();
        graph.resize(n+1);
        fee.resize(n);
        fee = passingFees;
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], t = edge[2];
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }
        memset(dp,-1,sizeof(dp));
        int mintime = rec(0,0,maxTime);
        return mintime == INT_MAX ? -1 : mintime;
    }
};
/*
here i have to take care of two things
 reach in <= maxTime and cost of travelling should be minimum

 the graph is build on u<->v and time is given so i have to use at max
 maxTime and minimise the cost to travell.
 naive greedy fails if i take shoetest time path it may give more cost

*/