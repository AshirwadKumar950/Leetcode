class Solution {
public:
    int minPartitions(string n) {
        int biggest = 0;
        for(int i = 0; i < n.length(); i++){
            biggest = max(biggest,n[i]-'0');
        }
        return biggest;
    }
};