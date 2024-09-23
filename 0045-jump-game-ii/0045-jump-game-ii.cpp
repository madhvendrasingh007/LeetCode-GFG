class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            int minJumps = nums.size() + 1;
            
            for (int step = nums[i]; step >= 1; --step) {
                int jumps = 1;
                if (i + step >= nums.size() - 1) {
                    jumps = 1;
                } else {
                    jumps = 1 + dp[i + step];
                }
                minJumps = min(minJumps, jumps);
            }
            
            dp[i] = minJumps;
        }
        
        return dp[0];
    }
};