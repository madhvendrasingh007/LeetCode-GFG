class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mapping;
        int prevStart = 0;
        int maxSum = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]]++;
            sum += nums[i];
            while (mapping[nums[i]] > 1)
            {
                sum = sum - nums[prevStart];
                mapping[nums[prevStart++]]--;
            }
            maxSum = (sum > maxSum) ? sum : maxSum;
        }
        return maxSum;
    }
};