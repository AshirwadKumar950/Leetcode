class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    long long power(ll a,ll b) {
        if(b == 0)
            return 1;
        ll half = power(a,b/2);
        ll result = (half*half) % mod;

        if(b%2 == 1) {
            result = (result*a) % mod;
        }
        return result;
    } 
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int q = queries.size();

        unordered_map<int,vector<vector<int>>>smallk;

        int block =ceil(sqrt(n));
        for(int i = 0; i < q; i++){
            int l = queries[i][0], r = queries[i][1];
            int k = queries[i][2], v = queries[i][3];
            if(k >= block){
                while(l <= r){
                    nums[l] = (1ll*nums[l]*v) % mod;
                    l += k;
                }
            }else{
                smallk[k].push_back(queries[i]);
            }
        }

        for(auto [k,querie] : smallk){
            vector<ll>diff(n,1);
            for(auto query : querie){
                int l = query[0];
                int r = query[1];
                int v = query[3];

                diff[l] = (1ll*diff[l]*v) % mod;
                int steps = (r-l)/k;
                int next = l + (steps+1)*k;

                if(next < n)
                    diff[next] = (1ll*diff[next]*power(v,mod-2))%mod;
            }

            for(int i = 0; i < n; i++) {
                if(i-k >= 0)
                diff[i] = (diff[i] * diff[i-k]) % mod;
            }

            //Apply diff to nums
            for(int i = 0; i < n; i++) {
                nums[i] = (1ll*nums[i]*diff[i]) % mod;
            }
        }
        int ans = 0;
        for(auto &num : nums){
            ans ^= num;
        }
        return ans;
    }
};