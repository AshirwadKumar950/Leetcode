class Solution {
public:
    typedef pair<int,int> pii;

    // Count walls in sorted array within [lo, hi] (by value, not index)
    int countWalls(vector<int>& walls, int lo, int hi) {
        if (lo > hi) return 0;
        int lb = (int)(lower_bound(walls.begin(), walls.end(), lo) - walls.begin());
        int ub = (int)(upper_bound(walls.begin(), walls.end(), hi) - walls.begin()) - 1;
        return (lb <= ub) ? ub - lb + 1 : 0;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pii> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {robots[i], distance[i]};
        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());

        vector<array<int,2>> dp(n+1, {0, 0});

        // Fill from right to left
        for (int i = n-1; i >= 0; i--) {
            int pos   = arr[i].first;
            int range = arr[i].second;

            int hardLeft  = (i == 0   ? 0 : arr[i-1].first + 1);
            int hardRight = (i == n-1 ? INT_MAX : arr[i+1].first - 1);

            int prevRightEnd = (i == 0) ? -1 : min((long long)arr[i-1].first + arr[i-1].second, (long long)pos - 1);

            int leftLo_A = max((long long)pos - range, (long long)hardLeft);
            int wallsL_A = countWalls(walls, (int)leftLo_A, pos);

            // Left walls robot i gets if prev fired RIGHT (overlap zone claimed by prev)
            int leftLo_B = max({(long long)pos - range, (long long)hardLeft, (long long)prevRightEnd + 1});
            int wallsL_B = countWalls(walls, (int)leftLo_B, pos);

            // Right walls robot i gets (same regardless of prev direction; right range never overlaps prev)
            int rightHi = min((long long)pos + range, (long long)hardRight);
            int wallsR  = countWalls(walls, pos, (int)rightHi);

            int bestIfPrevLeft  = max(wallsL_A + dp[i+1][0], wallsR + dp[i+1][1]);  

            int bestIfPrevRight = max(wallsL_B + dp[i+1][0], wallsR + dp[i+1][1]);  

            dp[i][0] = bestIfPrevLeft;
            dp[i][1] = bestIfPrevRight;
        }
        return dp[0][0];
    }
};