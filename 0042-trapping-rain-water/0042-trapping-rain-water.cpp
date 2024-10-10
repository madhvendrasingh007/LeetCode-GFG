class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater=0;
        int lMax=0,rMax=0;
        int n=height.size();
        int left=0,right=n-1;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lMax){
                    lMax=height[left];
                }
                else{
                    totalWater+=lMax-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rMax)
                {
                    rMax=height[right];
                }
                else{
                    totalWater+=rMax-height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};