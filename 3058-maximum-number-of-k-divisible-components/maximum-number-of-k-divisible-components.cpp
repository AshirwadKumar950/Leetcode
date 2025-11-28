class Solution {
public:
typedef long long ll;
    int comp = 0;
    vector<int>values;
    ll dfs(int node,int parent, int k, vector<vector<int>>&graph, vector<int>&values){
        ll sum = values[node];
        for(auto v : graph[node]){
            if(v == parent) continue;
            sum += dfs(v,node,k,graph,values);
        }
        if(sum % k == 0){
            comp++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>graph(n);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0,-1,k,graph,values);
        return comp;
    }
};