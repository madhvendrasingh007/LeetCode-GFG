class Solution {
public:
    int missingNumber(vector<int>& nums) {
                int n = nums.size();
        int sum = 0;
        int naturalNumbers = (n*(n+1)/2);
        
        for(int i : nums)
            sum += i;
        
        return naturalNumbers - sum;
    }
};