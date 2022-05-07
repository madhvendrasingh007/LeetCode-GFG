class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        stack<int> st;
        
        vec[0]=nums[0];
        
        vec[0]=nums[0];
        for(int i=1;i<n;++i){
            vec[i]=min(vec[i-1],nums[i]);
        }
        
        
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]>vec[i]){
                while(!st.empty() && st.top()<=vec[i]) 
                    st.pop();
                if(!st.empty() && st.top()<nums[i]) 
                    return true;
                st.push(nums[i]);
            } 
        }
        return false;
    }
};