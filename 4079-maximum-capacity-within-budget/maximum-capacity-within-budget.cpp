class Solution {
public:
    typedef pair<int,int> pii;
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pii>arr;
        for(int i = 0; i < n; i++){
            arr.push_back({costs[i],capacity[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int>prefix(n);
        prefix[0] = arr[0].second;
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1],arr[i].second);
        }
        
        // for(int i = 0; i < n; i++){
        //     cout<<"["<<arr[i].first<<","<<arr[i].second<<"]"<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<endl;
        int maxCost = 0;
        for(int i = 0; i < n; i++){
            if(arr[i].first < budget){
                maxCost = max(maxCost,arr[i].second);
            }
        }
        for(int i = 0; i < n; i++){
            int val = arr[i].second;
            int c1 = arr[i].first;

            int req = budget - c1 - 1;
            if(req <= 0) continue;
            int lb = 0, ub = i-1;
            int ans = -1;
            while(lb <= ub){
                int mid = lb + (ub-lb)/2;
                int c2 = arr[mid].first;
                if(c2 > req){
                    ub = mid - 1;
                }else{
                    ans = prefix[mid];
                    lb = mid + 1;
                }
            }
            if(ans == -1) continue;
            maxCost = max(maxCost,val+ans);
        }
        return maxCost;
    }
};