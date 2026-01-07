class Solution {
public:
    vector<int>nodesEachTree;

    int rec(vector<vector<int>>&tree, int node){
        int cal = 0;
        for(auto &child : tree[node]){
            cal += rec(tree,child);
        }
        nodesEachTree[node] = 1+cal;
        return nodesEachTree[node];
    }

    int countHighestScoreNodes(vector<int>& parents) {
        //precompute the number of nodes in each subtree
        int n = parents.size();
        nodesEachTree.assign(n,0);
        vector<vector<int>>tree(n);
        for(int i = 1; i < n; i++){
            tree[parents[i]].push_back(i);
        }
        rec(tree,0);
        long long maxi = INT_MIN;
        int ans = 0;

        //if i am about to remove ith node i need to see parent of it and its children
        for(int i = 0; i < n; i++){
            long long score = 1;
            if(i != 0){
                score = score*(n - nodesEachTree[i]);
            }
            for(auto& child : tree[i]){
                score *= nodesEachTree[child];
            }
            if(score > maxi){
                maxi = score;
                ans = 1;
            }else if(score == maxi){
                ans++;
            }
        }
        return ans;
    }
};