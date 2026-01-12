class Solution {
public:
    vector<int>cookies;
    int n,k;
    vector<int>children;
    int ans = INT_MAX;
    void rec(int i){
        if(i == n){
            ans = min(ans,*max_element(children.begin(),children.end()));
            return;
        }

        for(int j = 0; j < k; j++){
            children[j] += cookies[i];
            rec(i+1);
            children[j] -= cookies[i];
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        this->cookies = cookies;
        this->k = k;
        this->n = cookies.size();

        children.resize(k,0);
        /*this question is asking to ditribute the candy in such a
        manner that the child who gets the maximum candy gets the minimum
        maximum candy 
        */
        rec(0);
        return ans;

    }
};