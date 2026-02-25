class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](const int &a, const int &b){
            int b1 = __builtin_popcount(a);
            int b2 = __builtin_popcount(b);
            if(b1 == b2) return a < b;
            return b1 < b2;
        });
        return arr;
    }
};