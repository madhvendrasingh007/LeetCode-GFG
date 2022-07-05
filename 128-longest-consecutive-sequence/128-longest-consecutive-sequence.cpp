class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
            if (n == 0) 
                return 0;
        
        map<int, int>hm;
        for (int i = 0; i < n; i++)
            hm[nums[i]];
        
        auto prev = hm.begin();
        int c = 1, ans = 0;
        
        for (auto it = hm.begin(); it != hm.end(); it++) {
            if (prev->first+1 == it->first) {
                c++;
            } else {
                ans = max(ans, c); c = 1;
            }
            prev = it;
        }
        
        return max(ans, c);

    }
};