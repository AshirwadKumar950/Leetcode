class Solution {
public:
    string s,ts;
    int l;
    vector<vector<string>>result;
    vector<string>arr;
    
    bool isit(string s){
        if(s.length() == 0) return false;
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }

    void rec(int i){
        if(i == l){
            if(ts.empty())
            result.push_back(arr);
            return;
        }

        ts.push_back(s[i]);
        //if the string is palindrome then partition break or not
        if(isit(ts)){
            arr.push_back(ts);
            string t = ts;
            ts.clear();
            rec(i+1);
            ts = t;
            arr.pop_back();
        }
        rec(i+1);
        ts.pop_back();
    }
    vector<vector<string>> partition(string s) {
        this->s = s;
        l = s.length();
        rec(0);
        return result;
    }
};