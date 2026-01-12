class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int dp[1001][1<<10][2];
    vector<int>nums;
    vector<int>allMasks;
    int n;
    ll ans = 0;
    
    int rec(int i, int mask, int taken){
        if(i == n) return taken;
        int &res = dp[i][mask][taken];
        if(res != -1) return res;

        ll ans = 0;
        //don't take this element
        ans += rec(i+1,mask,taken);
        
        //take if possible it means if i have to take this than it's mask must not b1 -1
        int m = allMasks[nums[i]];
        if(m != -1 && ((m&mask) == 0)){
            ans += rec(i+1,mask|m,1);
        }
        return res = ans%MOD;
    }
    int squareFreeSubsets(vector<int>& nums) {
        /*
            so for every number taken in the subset the total number of 
            each prime factor can be max 1 and 1 itself can be any number
            of times.
            so when multiply this number in the subset than
            it is necessary to be taken care of that if it's factors
            are in that multiplication already don't add this we can keep
            track of this using a hashmap for now which could be faster using 
            a mask
        */
        this->nums = nums;
        this->n = nums.size();
        allMasks.resize(31);
        vector<int>primes = {2,3,5,7,11,13,17,19,23,29};

        for(int i = 1; i <= 30; i++){
            int val = i;
            int mask = 0;
            bool ok = true;
            for(int j = 0; j < 10; j++){
                int p = primes[j];
                int cnt = 0;
                while(val % p == 0){
                    val /= p;
                    cnt++;
                }
                if(cnt >= 2){
                    ok = false;
                    break;
                }
                if(cnt == 1) mask |= (1<<j);
            }
            if(!ok) allMasks[i] = -1;
            else allMasks[i] = mask;
        }

        memset(dp,-1,sizeof(dp));
        return rec(0,0,false);
    }
};