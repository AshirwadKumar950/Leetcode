class Solution {
public:
    typedef long long ll;
    ll dp[101][101];
;    ll rec(int i, int j, vector<int>&robot, vector<vector<int>>&factory){
        if(i==robot.size()) return 0;
        if(j==factory.size()) return LLONG_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        // i th robot can br repaired from this factory or the next factory
        ll leave = rec(i,j+1,robot,factory);

        ll cost = 0;
        for(int k = 0; k < factory[j][1] && i+k < robot.size(); k++){
            cost += abs(factory[j][0]-robot[i+k]);

            ll next = rec(i+k+1,j+1,robot,factory);
            if(next != LLONG_MAX)
            leave = min(leave,cost + next);
        }
        return dp[i][j] = leave;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        memset(dp,-1,sizeof(dp));
        return rec(0,0,robot,factory);
    }
};