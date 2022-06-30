class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
    
        int n=nums.size();
        for( int i=0; i<n;i++)
       {
           if(nums[i]==0)
           a++;
               if(nums[i]==1)
                   b++;
           if(nums[i]==2)
               c++;
       }
        nums.clear();
        
        for(int i=0;i<a;i++)
            nums.push_back(0);
        
            
        for(int i=0;i<b;i++)
             nums.push_back(1);
         
            
         for(int i=0;i<c;i++)
             nums.push_back(2);
    }
};