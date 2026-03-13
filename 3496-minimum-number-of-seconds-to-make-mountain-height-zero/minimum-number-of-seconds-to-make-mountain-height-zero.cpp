class Solution {
public:
    typedef long long ll;
    bool check(int mountainHeight, vector<int>& workerTimes, ll mid){
        // one worker can work at most mid days
        // in mid seconds each worker can reduce the mountain by
        // workers[i] + workers[i]*2 + .... <= mid
        // value of x will be found by that
        // workers[i]*(1+)
        ll totalwork = 0;
        for(auto &worker : workerTimes){
            totalwork += ((-1 + sqrt(1 + (8*mid)/worker))/2);
        }
        return totalwork >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll lb = 0, ub = 2e18+1, ans = -1;
        while(lb <= ub){
            ll mid = lb + (ub - lb)/2;
            if(check(mountainHeight, workerTimes, mid)){
                ans = mid;
                ub = mid - 1;
            }else lb = mid + 1;
        }
        return ans;
    }
};