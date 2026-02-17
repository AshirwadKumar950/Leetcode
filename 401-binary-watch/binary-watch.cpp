class Solution {
public:
    vector<string>result;
    void rec(int i,int turnedOn, string str){
        if(turnedOn < 0) return;
        if(i == 10){
            if(turnedOn == 0){
                int hour = 0, min = 0;
                int j = 0;
                for(int k = 3; k >= 0; k--,j++){
                    hour += (str[k] - '0')*(1<<j);
                }
                j = 0;
                for(int k = 9; k >= 4; k--, j++){
                    min += (str[k] - '0')*(1<<j);
                }
                if(hour > 11 || min > 59) return;
                string hr = to_string(hour);
                string mn = to_string(min);
                if(mn.size() == 1){
                    mn = '0' + mn;
                }
                result.push_back(hr+":"+mn);
            }
            return;
        }

        str[i] = '1';
        rec(i+1,turnedOn-1, str);
        str[i] = '0';
        rec(i+1,turnedOn, str);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        /*
            0000
            000000
        */
        string str = "0000000000";
        rec(0,turnedOn,str);
        return result;
    }
};