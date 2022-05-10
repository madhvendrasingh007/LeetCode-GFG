class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        combine(k,n,vec,1);
        return res;
    }
    void combine(int k,int n,vector<int> &vec,int start){
        if(!k && !n){
            res.push_back(vec);
            return;
        }
        
        if(n<=0 || !k){
            return;
        }
        
        for(int i=start;i<=9;i++){
            vec.push_back(i);
            combine(k-1,n-i,vec,i+1);
            vec.pop_back();
        }
    }
};