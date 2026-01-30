class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int l1 = s.length();
        int l2 = t.length();
        if(l1 != l2) return false;
        unordered_map<int,int>mp;
        int val;
        for(int i = 0; i < l1; i++){
            int c1 = s[i] - 'a';
            int c2 = t[i] - 'a';
            if(c1 == c2) continue;

            if(c1 < c2){
                val = c2 - c1;
            }else{
                val = 26 -(c1-c2);
            }
            if(mp.find(val) == mp.end()){
                if(val > k) return false;
                mp[val] = val;
            }else{
                int nv = mp[val] + 26;
                if(nv > k) return false;
                mp[val] = nv;
            }
        }
        return true;
    }
};