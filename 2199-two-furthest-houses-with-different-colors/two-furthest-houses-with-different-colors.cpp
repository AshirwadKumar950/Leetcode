class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        // assume first index is first element an then last
        // index is first element
        int ridx = INT_MIN;
        for(int i = n-1; i > 0; i--){
            if(colors[i] != colors[0]){
                ridx = i;
                break;
            }
        }
        if(ridx == INT_MIN) return -1;
        ans = max(ans,(ridx));
        int lidx = INT_MIN;
        for(int i = 0; i < n-1; i++){
            if(colors[i] != colors[n-1]){
                lidx = i;
                break;
            }
        }
        if(lidx == INT_MIN) return -1;
        ans = max(ans,(n-1-lidx));
        return ans;
    }
};