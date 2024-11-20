class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.empty() || matrix[0].empty()) return v;
        
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int top = 0, left = 0;

        while(left <= right && top <= bottom){
            
            for(int i = left; i <= right; i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return v;
    }
};