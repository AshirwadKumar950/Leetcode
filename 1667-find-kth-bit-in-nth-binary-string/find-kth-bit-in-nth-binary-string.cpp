class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        int j = 1;
        while(j < n){
            string temp = "";
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '0') temp += '1';
                else temp += '0';
            }
            reverse(temp.begin(),temp.end());
            string str = s + "1" + temp;
            s = str;
            j++;
            // cout<<s<<endl;
            // cout<<j<<endl;
        }
        return s[k-1];
    }
};