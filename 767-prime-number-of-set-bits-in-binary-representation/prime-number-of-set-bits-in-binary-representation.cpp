class Solution {
public:
    vector<int>prime;
    void seive(){
        prime[0] = true;
        prime[1] = true;
        for(int i = 2; i < 32; i++){
            if(!prime[i]){
                for(int j = i*i; j< 32; j += i){
                    prime[j] = true;
                }   
            }
        }
    }
    int countPrimeSetBits(int left, int right) {
        prime.assign(32,false);
        seive();
        int count = 0;
        for(int n = left; n <= right; n++){
            int bits = __builtin_popcount(n);
            if(!prime[bits]) count++;
        }
        return count;
    }
};