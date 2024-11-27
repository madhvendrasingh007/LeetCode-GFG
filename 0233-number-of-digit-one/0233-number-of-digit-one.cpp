class Solution {
public:
    int dp[21][3][21];
    int solve(int i ,int tight , string &n,int de  ){
        if(i== n.size()){
        return de ;     
        }
        if(dp[i][tight][de] != -1){
            return dp[i][tight][de];
        }
        int limit = tight?n[i] -'0':9;
        int ans  = 0 ;
        for(int d = 0; d<= limit ; d++){
          ans+= solve(i+ 1, tight &(limit ==d), n , de+(d==1));
        }
        return  dp[i][tight][de] = ans;
    }
    int countDigitOne(int n) {
     string s = to_string(n);
     memset(dp , -1 , sizeof(dp));
    
     return solve( 0 , 1,  s,0);
    }
};