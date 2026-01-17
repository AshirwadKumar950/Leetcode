class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int minpointssub = INT_MAX;
        int n = cardPoints.size();
        if(k == n) minpointssub = 0;
        int sl = n - k;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < n; r++){
            sum += cardPoints[r];
            if((r-l+1) == sl){
                minpointssub = min(minpointssub,sum);
                sum -= cardPoints[l++];
            }
        }
        return accumulate(cardPoints.begin(),cardPoints.end(),0) - minpointssub;
    }
};