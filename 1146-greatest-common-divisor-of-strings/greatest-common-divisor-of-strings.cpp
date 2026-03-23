class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        if(str1 + str2 != str2 + str1) return "";
        int len = __gcd(str1.length(), str2.length());
        return str1.substr(0, len);
    }
};