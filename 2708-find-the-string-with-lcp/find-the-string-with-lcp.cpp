class Solution {
public:
    // Step 1: validate matrix
    // Step 2: DSU initialize
    // Step 3: union based on lcp
    // Step 4: assign characters
    // Step 5: rebuild lcp and verify
    
    vector<int>parent,rank;

    int find(int node){
        if(parent[node] == node) return parent[node];
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) parent[u] = v;
        else if(rank[v] < rank[u]) parent[v] = u;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    string findTheString(vector<vector<int>>& lcp) {
        // longest common prefix bw the substrings word[i,n-1] and word[j,n-1]
        // alphabetically smallest string word that corresponds to lcp

        // Step - 1
        int n = lcp.size();
        for(int i = 0; i < n; i++){
            if(lcp[i][i] != (n - i)) return "";
            for(int j = i+1; j < n; j++){
                if(lcp[i][j] != lcp[j][i]) return "";
            }
        }
        parent.resize(n);
        rank.assign(n,0);
        for(int i = 0; i < n; i++) parent[i] = i;

        // here lcp[i][j] is lognest common prefix
        // if i start first string from i index and second from j index
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(lcp[i][j] > 0){
                    unite(i,j);
                }
            }
        }
        string ans = "";
        unordered_map<int,char>mp;
        char cur = 'a';
        for(int i = 0; i < n; i++){
            int p = find(i);
            if(mp.find(p) == mp.end()){
                if(cur > 'z') return "";
                mp[p] = cur++;
            }
        }
        for(int i = 0; i < n; i++){
            int p = find(i);
            ans.push_back(mp[p]);
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(ans[i] == ans[j]){
                    if(i+1 < n && j+1 < n)
                        dp[i][j] = 1 + dp[i+1][j+1];
                    else
                        dp[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != lcp[i][j]) return "";
            }
        }
        return ans;
    }
};