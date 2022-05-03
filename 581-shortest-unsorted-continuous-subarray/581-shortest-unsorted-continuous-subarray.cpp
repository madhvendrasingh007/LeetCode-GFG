class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> vec(nums.begin(), nums.end());
        sort(vec.begin(),vec.end());
        int n = nums.size(), start = 0, end = n - 1;
        while (start < nums.size() && nums[start] == vec[start]) {
            start++;
        }
        while (end > start && nums[end] == vec[end]) {
            end--;
        }
        return end + 1 - start; 
    }
};

