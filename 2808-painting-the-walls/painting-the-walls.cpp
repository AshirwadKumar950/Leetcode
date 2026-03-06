class Solution {
public:
    int dp[501][501];
    int rec(int i, int n, int used, vector<int>& cost, vector<int>& time){
        if(used >= n) return 0;
        if(i == n){
            return INT_MAX/2;
        }
        auto &res = dp[i][used];
        if(res != -1) return res;
        int dont = rec(i+1,n,used,cost,time);
        int paint = cost[i] + rec(i+1,n,used+1+time[i],cost,time);
        return res = min(dont,paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        /*
            cost and time of size n
            cost and time taken to paint n different walls
            two painters available

            1. paid painter- paints ith wall in time[i] time and takes cost[i]
                money
            2. free painter- paints any wall in 1 unit of time and takes 0 money
                but the free painter can be used if the paid painter is already
                occupied

            so if i make the painter paint this wall then the free painter can 
                paint time[i] walls in that time and total cost will still be
                cost[i];

            so this is a dp let's say the paid painter paint ith wall then the 
            free painter can paint any time[i] walls in the array
        */
        //i have to use the paid painter at most n/2 time with minimum cost
        memset(dp,-1,sizeof(dp));
        return rec(0, time.size(),0,cost, time);
    }
};