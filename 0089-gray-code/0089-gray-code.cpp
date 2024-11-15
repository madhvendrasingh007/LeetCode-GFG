class Solution {
public:
    void helper(int n, vector<int>& res){
        if(n==1){
            res.push_back(0);
            res.push_back(1);
            return ;
        
        }
        helper(n-1,res);
        int i= res.size()-1;
        while(i>=0){
            int val= res[i] | 1<<(n-1);
            res.push_back(val);
            i--;
        }
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        helper(n,res);
        return res;

    }
};