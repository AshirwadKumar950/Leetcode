class Solution {
public:
    vector<int>p;
    int comp;
    int find(int n){
        if(p[n] == n) return n;
        return p[n] = find(p[n]);
    }
    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        p[u] = v;
        comp--;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        p.resize(m);
        for(int i = 0; i < m; i++) p[i] = i;
        comp = m;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1) unite(i,j);
            }
        }
        return comp;
    }
};