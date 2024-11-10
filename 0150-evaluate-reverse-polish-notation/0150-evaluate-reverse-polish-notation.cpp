class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;

        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                int ans;
                if(tokens[i] == "+"){
                    ans = num2 + num1;
                }
                else if(tokens[i] == "-"){
                    ans = num2 - num1;
                }
                else if(tokens[i] == "*"){
                    ans = num2 * num1;
                }
                else{
                    ans = num2 / num1;
                }
                string str = to_string(ans);
                st.push(str);
            }
            else{
                st.push(tokens[i]);
            }
        }

        int ans = stoi(st.top());

        return ans;
    }
};