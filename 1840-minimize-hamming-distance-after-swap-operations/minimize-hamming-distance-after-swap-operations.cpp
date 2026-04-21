class Solution {
public:
    vector<int>parent;

    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v){
        parent[find(u)] = find(v);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        unordered_map<int,unordered_map<int,int>>groups;

        for(auto &swap : allowedSwaps){
            unite(swap[0],swap[1]);
        }

        for(int i = 0; i < n; i++){
            groups[find(i)][source[i]]++;
        }
        int hamming = 0;
        for(int i = 0; i < n; i++){
            int root = find(i);
            auto &freq = groups[root];
            if(freq.count(target[i]) && freq[target[i]] > 0){
                freq[target[i]]--; // matched consume this source value
            }else{
                hamming++;
            }
        }
        return hamming;
        /*
            source = [1,2,3,4], 
            target = [2,1,4,5], 
            allowedSwaps = [[0,1],[2,3]]

            [0,1,2,3]
        */   
    }
};