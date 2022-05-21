class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        if(amount==0) 
            return 0;
        
        vector<int> dp(amount+1, -1);
        
        dp[0]=0;
        
        for(int i=0; i<n; i++)
            for(int j=coins[i]; j<=amount; j++)
                if(dp[j]==-1&&dp[j-coins[i]]!=-1) 
                    dp[j]=dp[j-coins[i]]+1;				
                else if(dp[j]!=-1&&dp[j-coins[i]]!=-1) 
                    dp[j]=min(dp[j], dp[j-coins[i]]+1);
        return dp[amount];
    }
};