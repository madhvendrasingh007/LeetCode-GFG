class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find pivot — first index from right where nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find successor — smallest value in suffix greater than nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        // Step 3: Swap pivot with successor
        swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the suffix from i+1 to end
    // (if i == -1, this reverses the entire array → wraps to smallest permutation)
    reverse(nums.begin() + i + 1, nums.end());
}

};