class Solution {
public:
    typedef long long ll;
    const ll INF = 1e18;
    unordered_map<string,int>mp;
    vector<vector<ll>>dist;
    unordered_set<int>len;
    ll dp[1001];
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        /*
            what i would do is compress the substrings
            as there are 100 of them at max
            so give them all a number and then apply
            floyd warshal algo to collect the shortest path among them
        */
        int n = cost.size();
        int l = source.length();
        int val = 1;
        for(int i = 0; i < n; i++){
            string &s1 = original[i];
            string &s2 = changed[i];

            if(mp.find(s1) == mp.end()){
                mp[s1] = val++;
                len.insert((int)s1.length());
            }
            if(mp.find(s2) == mp.end()){
                mp[s2] = val++;
            }
        }
        dist.assign(val+1,vector<ll>(val+1,INF));
        for(int i = 0; i < n; i++){
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(1ll*dist[u][v], 1ll*cost[i]);
        }
        //apply floyd warshell algo
        for(int k = 1; k < val; k++){
            for(int i = 1; i < val; i++){
                for(int j = 1; j < val; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF){
                        dist[i][j] = min(1ll*dist[i][j] ,1ll*dist[i][k] + 1ll*dist[k][j]);
                    }
                }
            }
        }
        for(int i = 0; i <= 1000; i++) dp[i] = INF;
        dp[0] = 0;
        for(int i = 0; i < l; i++){
            if(dp[i] == INF) continue;

            if(source[i] == target[i]){
                dp[i+1] = min(dp[i+1],dp[i]);
            }
            for(int le : len){
                if(i+le > l) continue;
                string s1 = source.substr(i,le);
                string s2 = target.substr(i,le);

                if(mp.find(s1) != mp.end() && mp.find(s2) != mp.end()){
                    ll ct = dist[mp[s1]][mp[s2]];
                    if(ct != INF){
                        dp[i+le] = min(dp[i+le],dp[i] + ct);
                    }
                }
            }
        }
        return dp[l] == INF ? -1 : dp[l];
    }
};