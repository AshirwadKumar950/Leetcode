class DSU{
    public:
    vector<int>parent,rank;
    int components;

    DSU(int n){
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n,0);
        components = n;
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pv] < rank[pu]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
        components--;
        return true;
    }
};
class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int k, int mid){
        DSU dsu(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];
            // if must is 1 unite it also check uniting it doesn't form
            // a cycle
            if(must == 1){
                if(s < mid) return false;
                if(!dsu.unite(u,v)) return false;
            }
        }

        //put the rest of them in the graph
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];
            if(must == 0 && s >= mid){
                dsu.unite(u,v);
            }
        }

        int count = 0;
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];

            //now i can put this in my mst
            if(must == 0 && s < mid && 2*s >= mid){
                if(dsu.unite(u,v)){
                    count++;
                    if(count > k) return false;
                }
            }
        }
        return dsu.components == 1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lb = 1, ub = 2*1e5+1, ans = -1;
        while(lb <= ub){
            int mid = lb + (ub-lb)/2;
            if(check(n,edges,k,mid)){
                ans = mid;
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        return ans;
    }
};