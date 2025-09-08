class Solution {
public:
    bool check(vector<int>& nums) {
        int countDrop = 0, n = nums.size();
        for (int i = 1; i < n; ++i)
            if (nums[i] < nums[i - 1])
                ++countDrop;
        if (nums[0] < nums[n - 1])
            ++countDrop;
        return countDrop <= 1;
    }
};