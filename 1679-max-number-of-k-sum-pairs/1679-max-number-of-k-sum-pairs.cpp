class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start=0,end=(nums.size()-1);
        int temp=0;
        auto count = (nums[start]+nums[end]);
        while(start<end){
            if( (nums[start]+nums[end]) == k){
                // If their sum is equal to k then increment count and move both pointers inward by 1 (sort of removing the K-Sum pair)
                temp++;
                start++;
                end--;
            }
            else if((nums[start]+nums[end]) > k)
                // If their sum was more than k then move end pointer inward
                end--;
            else
                // If their sum was less than k then move start pointer inward
                start++;
        }
        return temp;
    }
};