class Solution {
public:
    
    int n, m, target;
    vector<int> houses;
    vector<vector<int> > cost;
    int dp[101][21][101]; //dp[i][j][t] = min cost to paint i houses with j being the color of i-1 house and target reached t
    
    int util(int i, int j, int t){
        if(i>=m){
            if(t==target)
                return 0;
            else
                return 1e9;
        }
        
        if(dp[i][j][t]!=-1)
            return dp[i][j][t];
        
        if(houses[i]>0){
            if(j!=houses[i])
                return dp[i][j][t]=util(i+1, houses[i], t+1);
            else
                return dp[i][j][t]=util(i+1, houses[i], t);
        }
        else{
            int ans=1e9;
            for(int c=1; c<=n; c++){
                if(c==j)
                    ans=min(ans, util(i+1, c, t)+cost[i][c-1]);
                else
                    ans=min(ans, util(i+1, c, t+1)+cost[i][c-1]);
            }
            return dp[i][j][t]=ans;
        }
    }
    
    int minCost(vector<int>& h, vector<vector<int>>& cst, int m1, int n1, int tt) {
        houses=h; cost=cst; m=m1; n=n1; target=tt;
        memset(dp, -1, sizeof(dp));
        int ans=util(0, 0, 0);
        if(ans>=1e9)
            return -1;
        else
            return ans;
    }
};
