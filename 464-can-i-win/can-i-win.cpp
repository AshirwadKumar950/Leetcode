class Solution {
public:
    int n;
    int dp[1<<20];
    bool rec(int mask, int rem){
        if(rem <= 0) return false;
        if(dp[mask] != -1) return dp[mask];
        for(int i = 0; i < n; i++){
            //if this number is not used
            if(!(mask&(1<<i))){
                bool v = rec((mask|(1<<i)), rem - (i+1));
                if(v == false){
                    return dp[mask] = true;
                }
            }
        }
        return dp[mask] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        /*
         so both play optimal 
         initially sum = 0;
         player 1 can choose any no from 1 to 20
         if he choose this other player cant choose this
         make only states for player one 
         if somehow player1 gets desiredTotal before player2
         he wins.
         so if first platers total >= desiredtotal he wins
        */
        if(desiredTotal <= 0) return true;
        int maxi = maxChoosableInteger*(maxChoosableInteger+1)/2;
        cout<<maxi<<endl;
        if(maxi < desiredTotal) return false; 
        n = maxChoosableInteger;
        memset(dp,-1,sizeof(dp));
        return rec(0,desiredTotal);
    }
};