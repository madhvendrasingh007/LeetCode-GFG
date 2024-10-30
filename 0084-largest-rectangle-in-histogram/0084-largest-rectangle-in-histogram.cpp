class Solution {
public:
    vector<int> findNse(vector<int> arr, int n){
        stack<int> st;
        vector<int> nse(n, -1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPse(vector<int> arr, int n){
        stack<int> st;
        vector<int> pse(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = findNse(heights, n);
        vector<int> pse = findPse(heights, n);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, (heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
};