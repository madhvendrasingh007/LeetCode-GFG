class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int>ans;
        deque<int>dq;

        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty()  && dq.front() == i-k)  //out of bound case
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i])    //check form the right side
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};