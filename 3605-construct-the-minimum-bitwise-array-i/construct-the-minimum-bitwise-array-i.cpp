class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        /*
            [2,3,5,7,11,13,17,19,23,29,31]
            2 -     000010
            3-      000011      1 | 2 = 3
            5 -     0000101     4 | 5 = 5
            7 -     0000111     6 | 7 = 7 or 3 | 4 = 7
            11 -    0001011     9 | 10 = 11 
            13 -    0001101     12 | 13 = 13
            17 -    0010001     16 | 17 = 17
            19 -    0010011     17 | 18 = 19
            23-     0010111     19 | 20 = 23
            29-     0011101     28 | 29 = 29
            31-     0011111     15 | 16 = 31
        */
        int n = nums.size();
        vector<int>ans(n);
    
        for(int i = 0; i < n; i++){
            bool isit = false;
            int val = nums[i];
            for(int j = 31; j >= 0; j--){
                if(val&(1<<j)){
                    int newnum = val & ~(1 << j);
                    if((newnum|(newnum+1)) == val){
                        ans[i] = newnum;
                        isit = true;
                        break;
                    }
                }
                if(!isit) ans[i] = -1;
            }
        }
        return ans;
    }
};