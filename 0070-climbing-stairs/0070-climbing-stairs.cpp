class Solution {
    vector<int>dp;
    int h(int n, int i){
        if(i == n)
        return 1;
        if(i > n)
        return 0;
        if(dp[i] != -1)
        return dp[i];
        int count = h(n, i + 1);
        count += h(n, i + 2);
        return dp[i] = count;
    }
public:
    int climbStairs(int n) {
        dp = vector<int>(n + 1, -1);
        return h(n, 0);
    }
};