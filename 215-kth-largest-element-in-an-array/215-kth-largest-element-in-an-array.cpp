class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        sort(nums.begin(),nums.end());
        for(auto i=0;i<nums.size();i++){
           ans=nums[nums.size()-k];
        }
        return ans;
    }
};