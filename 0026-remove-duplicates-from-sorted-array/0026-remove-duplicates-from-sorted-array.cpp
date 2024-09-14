class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lw = 0, hg = 0, n = nums.size(); 
        while(hg < n){
            if(nums[lw] != nums[hg]){
                swap(nums[++lw], nums[hg]);
            }
            hg++;
        } 
        return lw + 1;
    }
};