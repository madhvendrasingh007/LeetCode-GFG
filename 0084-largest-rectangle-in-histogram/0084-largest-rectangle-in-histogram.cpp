class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA=0,n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && ( i==n || heights[st.top()]>=heights[i])){
                // picking up the previous rectange bar
                int currHeight=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    // as we are storing indexes in stack and those are needed for finding the width
                    width = i-st.top()-1;
                }
                maxA= max(maxA, currHeight*width);
            }
            st.push(i);
        }
        return maxA;
    }
};