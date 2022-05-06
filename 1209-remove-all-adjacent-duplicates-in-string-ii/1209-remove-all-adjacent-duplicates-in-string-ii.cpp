class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> st;
        string str;
        for(auto c : s){
            if(st.empty() || c!=str.back())
			    st.push(str.size());
		    
            str += c;
		    
            if(str.size() - st.top() == k){
			    str.erase(st.top());
			    st.pop();
		    }
        }
        return str;
    }
};