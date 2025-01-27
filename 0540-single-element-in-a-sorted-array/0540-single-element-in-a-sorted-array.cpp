class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int sum = 0;

        for( auto &it : nums ) 
            sum ^= it;

        return sum ;
    }
};