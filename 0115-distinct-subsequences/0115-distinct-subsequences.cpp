class Solution {
public:
    int dp[1005][1005];
     int fn(string &s, string &t, int i, int j ){
        if(j==t.size())return 1;
        if(i==s.size()||j==t.size())return 0;
         if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans+=fn(s,t,i+1,j+1);

        }
        ans+=fn(s,t,i+1,j);
        return dp[i][j]=ans;
     }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return fn(s,t,0,0);
    }
};