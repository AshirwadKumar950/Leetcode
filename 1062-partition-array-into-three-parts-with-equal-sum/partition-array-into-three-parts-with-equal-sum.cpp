class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        for(auto &v : arr){
            s += v;
        }
        if(s % 3 != 0) return false;
        int val = s/3;
        s = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            s += arr[i];
            if(s == val){
                s = 0;
                count++;
            }
        }
        if(count >= 3) return true;
        return false;
    }
};