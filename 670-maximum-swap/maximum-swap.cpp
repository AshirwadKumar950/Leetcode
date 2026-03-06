class Solution {
public:
    int maximumSwap(int num) {
        vector<int>arr;
        int t = num;
        while(t != 0){
            arr.push_back(t%10);
            t/=10;
        }
        reverse(arr.begin(),arr.end());
        vector<int>res = arr;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.size(); j++){
                if(i == j) continue;
                swap(arr[i],arr[j]);
                res = max(res,arr);
                swap(arr[i],arr[j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < res.size(); i++){
            ans = ans*10 + res[i];
        }
        return ans;
    }
};