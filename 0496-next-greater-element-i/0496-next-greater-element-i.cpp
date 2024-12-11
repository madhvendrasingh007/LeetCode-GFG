class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int> mp;
        stack<int> st;
        mp[nums2[n-1]] = -1;
        st.push(nums2[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && nums2[i]>=st.top())        {
                st.pop();
            }
            if(st.empty())
                mp[nums2[i]] = -1;
            else 
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++)
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};