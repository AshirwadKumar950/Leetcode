class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lb = 0, ub = letters.size()-1;
        char ans = '1';
        while(lb <= ub){
            int mid = lb + (ub-lb)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                ub = mid - 1;
            }else{
                lb = mid + 1;
            }
        }
        return ans == '1' ? letters[0] : ans;
    }
};