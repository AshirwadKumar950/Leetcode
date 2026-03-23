class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();

        if(str1 + str2 != str2 + str1) return "";
        unordered_map<int,int>mp1,mp2;
        for(auto &c : str1){
            mp1[c]++;
        }
        for(auto &c : str2){
            mp2[c]++;
        }
        int g1 = 0, g2 = 0;
        for(auto &[k,f] : mp1){
            g1 = __gcd(g1,f);
        }
        for(auto &[k,f] : mp2){
            g2 = __gcd(g2,f);
        }

        int l = (l1)/g1;
        cout<<"GCD of first is "<<g1<<endl;
        cout<<"GCD of second is "<<g2<<endl;
        cout<<"Length of each block is "<<l<<endl;
        int g3 = __gcd(g1,g2);
        cout<<"GCD of both is "<<g3<<endl;
        return str1.substr(0,l*g3);
    }
};