class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();

        int start = min(l1,l2);
        while(start > 0){
            string s = str1.substr(0,start);
            string s1 = "";
            string s2 = "";
            while(s1.length() < l1){
                s1 += s;
            }
            // cout<<"After operation s1"<<s1<<endl;
            while(s2.length() < l2){
                s2 += s;
            }
            // cout<<"After operation s2"<<s2<<endl;
            if(s1 == str1 && s2 == str2){
                return str1.substr(0,start);
            }
            start--;
        }
        return "";
    }
};