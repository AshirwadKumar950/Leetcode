class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int firstColor = colors[i];
            for(int j = i+1; j < n; j++){
                int secondColor = colors[j];
                if(firstColor != secondColor){
                    ans = max(ans,j-i);
                }
            }
        }
        return ans;
    }
};