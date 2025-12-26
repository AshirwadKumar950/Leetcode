class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int ty = 0;
        for(auto &v : customers){
            if(v == 'Y') ty++;
        }
        int y = 0, neg = 0;
        int ans = 0;
        int panelty = ty;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y') y++;
            else neg++;

            int pen = neg + (ty-y);
            if(pen < panelty){
                panelty = pen;
                ans = i+1;
            }
        }
        return ans;
    }
};