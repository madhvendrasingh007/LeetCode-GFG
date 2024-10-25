class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> st;
        
        for (int i = 0; i < num.length(); i++) {
            while (!st.empty() && st.back() > num[i] && k > 0) {
                k--;
                st.pop_back();
            }
            st.push_back(num[i]);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        while(!st.empty() && st.front()=='0'){
            st.pop_front();
        }

        string ans;
        
        copy(st.begin(), st.end(), back_inserter(ans));
        
        return !ans.size() ? "0" : ans;
    }
};