class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        /*
            how would i get longest ncreasing consecutive subarray here
            [14,15,16,17]
            [2,3,4,6,8,10,12,14,15,16,17]
            put all the numbers in a set
            then pick a number from h and run a while loop to 
            see if it's +1 value is present in it if it is check for
            next greater value 
        */
        unordered_set<int>st1,st2;
        for(auto &val : h){
            st1.insert(val);
        }
        for(auto &val : v){
            st2.insert(val);
        }
        int max1 = 1,max2 = 1;
        for(auto &val : h){
            if(st1.find(val-1) != st1.end()) continue;
            else{
                int temp = val;
                int size = 0;
                while(st1.find(temp) != st1.end()){
                    temp++;
                    size++;
                }
                max1 = max(max1,size);
            }
        }
        for(auto &val : v){
            if(st2.find(val-1) != st2.end()) continue;
            else{
                int temp = val;
                int size = 0;
                while(st2.find(temp) != st2.end()){
                    temp++;
                    size++;
                }
                max2 = max(max2,size);
            }
        }
        int val = min(max1,max2)+1;
        return val*val;
    }
};