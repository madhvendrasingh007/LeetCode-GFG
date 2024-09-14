class Solution {
public:
    vector<int> generateRows(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int i=1; i<row; i++){
            ans *= (row-i);
            ans /= i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int row=1; row<=numRows; row++){
            ans.push_back(generateRows(row));
        }
        return ans;
    }
};