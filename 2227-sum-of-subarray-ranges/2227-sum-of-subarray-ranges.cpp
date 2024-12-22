class Solution {
public:
vector<int> NSE(vector<int>&nums){
    stack<int>st;
    int n = nums.size();
    vector<int> nse(n,0);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = n;
        }
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}
vector<int> PSE(vector<int>&nums){
    stack<int> st;
    int n = nums.size();
    vector<int> pse(n,0);
    for(int i=0 ;i<n;i++){
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
        if(st.empty()) pse[i] =  -1;
        else pse[i] = st.top();
        st.push(i);
    }
    return pse;
}
vector<int> NGE(vector<int>&nums){
    stack<int> st;
    int n = nums.size();
    vector<int> nge(n,0);
    for(int i= n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        if(st.empty()){
            nge[i] = n;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}
vector<int> PGE(vector<int>&nums){
    stack<int>st;
    int n = nums.size();
    vector<int> pge(n,0);
    for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();
        st.push(i);
    }
    return pge;
}
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<int> nse = NSE(nums);
        vector<int> pse = PSE(nums);
        vector<int> nge = NGE(nums);
        vector<int> pge = PGE(nums);
        long long largest =0, smallest =0;
        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long left1 = i - pge[i];
            long long right1 = nge[i] - i;
            largest += (left*right*nums[i]);
            smallest += (left1*right1*nums[i]);
        }
        return abs(largest-smallest);
    }
};