class Solution {
public:
    int dp[201][201] = {};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int longest = 0;
        for (int i = 0; i < matrix.size(); i++) 
            
            for (int j = 0; j < matrix[0].size(); j++)
                longest = max(longest, path(matrix, i, j));
            
        
        return longest;
    }
    
    int path(vector<vector<int>>& matrix, int i = 0, int j = 0, int n = -1) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= n) 
            return 0;
        
        if (dp[i][j]) 
            return dp[i][j];
        
        int longest = 0;
        
        longest = max(longest, path(matrix, i+1, j, matrix[i][j]));
        longest = max(longest, path(matrix, i-1, j, matrix[i][j]));
        longest = max(longest, path(matrix, i, j+1, matrix[i][j]));
        longest = max(longest, path(matrix, i, j-1, matrix[i][j]));
        dp[i][j] = longest+1;
        return dp[i][j];
    }
};