class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        int l = s1.length();
        for(int i = 0; i < l; i++){
            if(i%2 == 0) mp1[s1[i]]++;
            else mp2[s1[i]]++;
        }
        for(int i = 0; i < l; i++){
            if(i%2==0) mp1[s2[i]]--;
            else mp2[s2[i]]--;

            if(mp1[s2[i]]==0) mp1.erase(s2[i]);
            if(mp2[s2[i]]==0) mp2.erase(s2[i]);
        }
        return mp1.empty() && mp2.empty();
    }
};