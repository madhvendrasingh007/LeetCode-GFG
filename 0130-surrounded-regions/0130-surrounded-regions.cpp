class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int j=0; j<m; j++){
            if(grid[0][j] == 'O'){
                vis[0][j] = 1;
                q.push({0, j});
            }
            if(grid[n-1][j] == 'O'){
                vis[n-1][j] = 1;
                q.push({n-1, j});
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 'O'){
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if(grid[i][m-1] == 'O'){
                vis[i][m-1] = 1;
                q.push({i, m-1});
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vector<int> a = {-1, 0, 1, 0};
            vector<int> b = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nr = r + a[i];
                int nc = c + b[i];
                if(nr>0 && nr<n && nc>0 && nc<m && vis[nr][nc] == 0 && grid[nr][nc] == 'O'){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0){
                    grid[i][j] = 'X';
                }
            }
        }
    }
};