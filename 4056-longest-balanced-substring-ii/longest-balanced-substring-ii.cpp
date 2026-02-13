class Solution {
public:
    int onechar(string &s, char ch){
        int l = s.length();
        int maxi = 0;
        int cnt = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == ch){
                cnt++;
            }else{
                cnt = 0;
            }
            maxi = max(maxi,cnt);
        }
        //cout<<"1 maxi is"<<maxi<<endl;
        return maxi;
    }
    int twochar(string& s, char char1, char char2){
        int l = s.length();
        int c1 = 0, c2 = 0;
        int maxi = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i = 0; i < l; i++){
            if(s[i] == char1){
                c1++;
            }else if(s[i] == char2){
                c2++;
            }else{
                c1 = 0;c2 = 0;
                mp.clear();
                mp[0] = i;
                continue;
            }
            int diff = c1 - c2;
            if(mp.find(diff) != mp.end()){
                maxi = max(maxi,i - mp[diff]);
            }else{
                mp[diff] = i;
            }
        }
        // cout<<"2 maxi is"<<maxi<<endl;
        return maxi;
    }


    int allthree(string &s, char c1, char c2, char c3){
        int l = s.length();
        //abcabccccabcabcabc
        //a and b diff and b and c diff
        map<pair<int,int>,int>mp;
        mp[{0,0}] = -1;
        int a,b,c;
        a=b=c=0;
        int ans = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == c1){
                a++;
            }else if(s[i] == c2){
                b++;
            }else{
                c++;
            }
            int a1 = a-b;
            int b1 = b-c;
            if(mp.find({a1,b1}) != mp.end()){
                ans = max(ans,i-mp[{a1,b1}]);
            }else{
                mp[{a1,b1}] = i;
            }
        }
        // cout<<"3 maxi is"<<ans<<endl;
        return ans;
    }
    int longestBalanced(string s) {
        int l = s.length();
        //for a single character do it 
        //for two cahracters check the biggest length 
        //for three cahracters check the biggest length
        int ans = 0;
        ans = max({ans,onechar(s,'a'),onechar(s,'b'),onechar(s,'c')});
        ans = max({ans,twochar(s,'a','b'),twochar(s,'b','c'),twochar(s,'a','c')});
        
        ans = max(ans,allthree(s,'a','b','c'));
        return ans;
    }
};