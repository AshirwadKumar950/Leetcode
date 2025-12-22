class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a , b;
        a = b = LLONG_MAX;
        for(int x : nums){
            if(x <= a){
                a = x;
            }else if(x <= b){
                b = x;
            }else return true;
        }
        return false;
    }
};