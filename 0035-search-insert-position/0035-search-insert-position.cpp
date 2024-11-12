class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if(target > nums[r])
        return r + 1;
        int mid = 0;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == target)
            return mid;
            if(nums[mid] < target)
            l = mid + 1;
            if(nums[mid] > target)
            r = mid - 1;
            
        }
        return l;
    }
};