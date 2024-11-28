class Solution {
public:
    int numSquares(int n) {  
        int dp[10001];
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            dp[i] = 10000;
            for(int j = 1; j * j <= i; ++j){               
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }           
        }
        return dp[n];
    }
};