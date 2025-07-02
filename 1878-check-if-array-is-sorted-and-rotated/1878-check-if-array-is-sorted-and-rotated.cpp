class Solution {
public:
    bool check(vector<int>& nums) {
        int breaks = 0;
        int n = nums.size();
        
        // Count adjacent breaks
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) breaks++;
        }
        
        // Count circular break
        if (nums[n - 1] > nums[0]) breaks++;
        
        return breaks <= 1;
    }
};