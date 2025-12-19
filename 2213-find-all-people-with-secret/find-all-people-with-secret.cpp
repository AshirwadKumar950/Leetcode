class UnionFind{
    public:
    vector<int>parent;
    vector<int>rank;
    UnionFind(int n){
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u){
        if(u == parent[u]) return parent[u];
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    bool disjoint(int u, int v){
        return find(u) != find(v);
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[&](const vector<int>&a, const vector<int>&b){
            return a[2] < b[2];
        });

        UnionFind dsu(n);
        dsu.unite(0,firstPerson);

        int i = 0;
        while(i < meetings.size()){

            int time = meetings[i][2];
            vector<pair<int,int>>edges;
            unordered_set<int>people;

            while(i < meetings.size() && meetings[i][2] == time){
                edges.push_back({meetings[i][0],meetings[i][1]});
                people.insert(meetings[i][0]);
                people.insert(meetings[i][1]);
                i++;
            }

            for(auto &e : edges){
                dsu.unite(e.first,e.second);
            }
            for(int p : people){
                if(dsu.find(p) != dsu.find(0)){
                    dsu.parent[p] = p;
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(dsu.find(i) == dsu.find(0)) ans.push_back(i);
        }
        return ans;
    }
};