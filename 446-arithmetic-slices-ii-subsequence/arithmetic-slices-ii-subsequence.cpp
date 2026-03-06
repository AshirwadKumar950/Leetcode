// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         //pick combination of any two and now for third and upward run dp

//         int ans = 0;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(i == j) continue;
//                 ans += ans(0,diff);
//             }
//         }
//     }
// };
class Solution {
public:
    vector<int> nums;
    int n;
    map<pair<int,long long>, long long> memo;

    long long rec(int i, long long diff) {
        auto key = make_pair(i, diff);
        if (memo.count(key)) return memo[key];

        long long ans = 0;

        for (int j = 0; j < i; j++) {
            if ((long long)nums[i] - nums[j] == diff) {
                ans += 1;               // pair (j,i)
                ans += rec(j, diff);    // extend earlier sequences
            }
        }

        return memo[key] = ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                ans += rec(j, diff);
            }
        }

        return ans;
    }
};