class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> res(q, -1);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        // so if 8 is present at 6th index so I need to find 
        // minimal distance of another 8 in the array from this 6 
        for(int i = 0; i < q; i++){
            int idx = queries[i];
            int ele = nums[idx];
            auto &vec = mp[ele];

            if(vec.size() <= 1) continue;

            int thisidx = -1;
            int lb = 0, ub = vec.size()-1;
            while(lb <= ub){
                int mid = (lb + ub)/2;
                if(vec[mid] == idx){
                    thisidx = mid;break;
                }else if(vec[mid] < idx){
                    lb = mid + 1;
                }else ub = mid - 1;
            }
            if(thisidx == -1) continue;
            int x = vec.size();
            int nextidx = vec[(thisidx+1)%x];
            int preidx = vec[(thisidx-1+x)%x];
            int dist = min({abs(idx-nextidx),n-abs(idx-nextidx),n-abs(idx-preidx),abs(idx-preidx)});

            res[i] = dist;
        }

        return res;
    }
};