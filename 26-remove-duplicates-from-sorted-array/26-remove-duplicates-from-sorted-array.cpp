class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        vector<int> :: iterator it;
        
        for (auto it = nums.begin(); it+1 != nums.end(); it++)
        {  
            if(*it == *(it+1))
            {
                nums.erase(it);
                it--;
            }
                
        }
        
        
        return nums.size();
    }
};