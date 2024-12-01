class Solution {
public:
    void solve(int index , vector<int>&nums , vector<vector<int>>&ashu ,  int n)
    {
        if(index >= n)
        ashu.push_back(nums);
        for(int  i = index ; i < n ; i++)
        {
            swap(nums[i] , nums[index]);
            solve(index + 1 , nums , ashu , n);
            swap(nums[index] , nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin())
        // unordered_set<vector<int>>st;
        vector<vector<int>>ashu;
        int index = 0;
        solve(index , nums , ashu , n );
        return ashu;
    }
};