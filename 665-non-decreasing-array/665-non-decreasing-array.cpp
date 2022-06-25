class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=0,n=nums.size();
        if(n<=2)
            return(true);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(i+1<n && nums[i-1]<=nums[i+1])
                {
                    c++;
                    continue;
                }
                else if(i+1<n && i-2>=0 && nums[i]<=nums[i+1] && nums[i]>=nums[i-2])
                {
                    c++;
                    continue;
                }
                else if(i+1<n && i<2 && nums[i]<=nums[i+1])
                {
                    c++;
                    continue;
                }
                else if(i==n-1)
                {
                    return(c==0);
                }
                return(false);
            }
        }
        return(c<=1);
    }
};