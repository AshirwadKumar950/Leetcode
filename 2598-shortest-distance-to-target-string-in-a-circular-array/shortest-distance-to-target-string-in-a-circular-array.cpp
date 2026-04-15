class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n+1;
        for(int i = startIndex,x = 0; x < n; x++, i=(i+1)%n){
            if(words[i] == target) ans = min(ans,x);
        }
        for(int i = startIndex,x = 0; x < n; x++, i=(i-1+n)%n){
            if(words[i] == target) ans = min(ans,x);
        }
        return ans == n+1 ? -1 : ans;
    }
};