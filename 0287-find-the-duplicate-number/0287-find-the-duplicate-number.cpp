class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        vector<int>hash(n, 0);
        for (int i = 0; i < n; i++) {
            hash[nums[i] - 1] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (hash[i] >= 2)
                ans = i+1;
        }
        return ans;
    }
};