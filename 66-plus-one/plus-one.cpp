class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int rem = 1;
        if(digits[n-1] < 9){
            digits[n-1]++;
            return digits;
        }else{
            int i = n-1;
            while(i >= 0){
                int val = digits[i] + rem;
                digits[i] = val%10;
                rem = val/10;
                i--;
            }
        }
        if(rem != 0){
            reverse(digits.begin(),digits.end());
            digits.push_back(rem);
            reverse(digits.begin(),digits.end());
        } 
        return digits;
    }
};