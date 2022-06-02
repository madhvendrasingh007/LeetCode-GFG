class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> res(size(matrix[0]), vector<int>(size(matrix)));
            
        for(int row = 0; row < size(matrix); row++)
            for(int col = 0; col < size(matrix[0]); col++)
                res[col][row] = matrix[row][col];
            
        return res;
    }
};