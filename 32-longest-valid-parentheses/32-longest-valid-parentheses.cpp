class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int len = s.length();
        int count=0;
        
        if(len==0)
            return 0;
        
        st.push(-1);
        
        for(int i=0;i<len;i++)
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                
                // For every ‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length of the currently encountered valid string of parentheses.
                if(!st.empty()) // Just to make sure we don't try to pop an empty stack.
                {
                    st.pop();
                    // If while popping the element, the stack becomes empty, we push the current element's index onto the stack. In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.
                    if(st.empty())
                        st.push(i);
                    else
                        count = max(count, i - st.top());
                }
            }
        return count;
    }
};