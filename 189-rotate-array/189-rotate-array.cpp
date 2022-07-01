class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size()-1;
    vector<int> ans;
    while(k>n+1){
        int temp=nums[n];
        nums.pop_back();
        nums.insert(nums.begin(),temp);
        k--;
    }
    if(k<=n){
        int x=n-k+1;
        for(int i=x;i<=n;i++){
            ans.push_back(nums[i]);   
        }
        for(int i=0;i<x;i++){
            ans.push_back(nums[i]);    
        }

        nums=ans;
        

    }    
    }
    
};