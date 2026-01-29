class Solution {
public:
    typedef long long ll;
    const int INF = 1e9;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        int l = source.length();
        vector<vector<int>>dist(26,vector<int>(26,INF));
        for(int i = 0; i < n; i++){
            int u = original[i] - 'a', v = changed[i] - 'a', c = cost[i];
            if(u == v) continue;
            dist[u][v] = min(dist[u][v],c);
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] < INF && dist[k][j] < INF){
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < l; i++){
            if(source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            int ct = dist[u][v];
            if(ct == INF) return -1;
            ans += 1ll*ct; 
        }
        return ans;
    }
};