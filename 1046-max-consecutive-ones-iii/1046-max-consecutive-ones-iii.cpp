class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int flip=0, left=0, right=0, maxlen=0;

        while(right<nums.size())
        {
            if(nums[right]==0)
                flip++;

            if(flip>k)
            {
                if(nums[left]==0)
                    flip--;

                left++;
            }

            maxlen = max(maxlen, right-left+1);

            right++;

        }

        return maxlen;
        
    }
};