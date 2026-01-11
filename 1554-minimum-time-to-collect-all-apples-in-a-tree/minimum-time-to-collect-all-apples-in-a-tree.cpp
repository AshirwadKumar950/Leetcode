class Solution {
public:
    vector<vector<int>>tree;
    pair<bool,int>dfs(int root, int parent, vector<bool>&hasApple){
        bool has = hasApple[root];
        int cost = 0;

        for(auto &child : tree[root]){
            if(child == parent) continue;
            auto [childHas, childCost] = dfs(child,root,hasApple);
            if(childHas){
                cost += childCost + 2;
                has = true;
            }
        }

        return {has,cost};
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        tree.resize(n);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        return dfs(0,-1,hasApple).second;
    }
};