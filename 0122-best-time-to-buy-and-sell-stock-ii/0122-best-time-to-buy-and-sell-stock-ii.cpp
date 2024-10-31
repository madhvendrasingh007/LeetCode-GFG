class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Create a memoization table
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
    
    int solve(int ind, int buy, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == arr.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        if (buy == 1) {
            // Two options: buy or not buy
            // Buy
            int op1 = -arr[ind] + solve(ind + 1, 0, arr, dp);
            // Don't buy
            int op2 = solve(ind + 1, 1, arr, dp);
            profit = max(op1, op2);
        } else {
            // Two options: sell or not sell
            // Sell
            int op1 = arr[ind] + solve(ind + 1, 1, arr, dp);
            // Don't sell
            int op2 = solve(ind + 1, 0, arr, dp);
            profit = max(op1, op2);
        }

        dp[ind][buy] = profit;
        return dp[ind][buy];
    }
};
