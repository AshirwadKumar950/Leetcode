class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        vector<int>ans(rowIndex+1,0);
        ans[0] = ans[1] = 1;
        int val = 3;
        for(int i = 1; i <= rowIndex-1; i++){
            vector<int>temp(rowIndex+1,0);
            temp[0] = 1;
            for(int j = 1; j < val-1; j++){
                temp[j] = ans[j-1] + ans[j];
            }
            temp[val-1] = 1;
            val++;
            ans = temp;
        }
        for(int i = 0; i < rowIndex; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
};