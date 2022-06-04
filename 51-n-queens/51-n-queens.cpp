class Solution {
public:    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        auto dfs=[&](auto&&dfs,int a,int b,int c,int k){
            if(k==n){ans.push_back(board);return;}
            for(int i=~(a|b|c)&((1<<n)-1);i;){
                int p=i&-i;
                board[k][log2(p)]='Q';
                dfs(dfs,(a|p)<<1,(b|p)>>1,c|p,k+1);
                board[k][log2(p)]='.';
                i-=p;
            }
        };
        dfs(dfs,0,0,0,0);
        return ans;
    }
};