class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;

        for(int i = 0; i<n; i++){
            while( !s.empty() && k > 0 && ( s.top() - '0' ) > ( num[i] - '0' ) ){
                s.pop();
                k--;
            }
        s.push(num[i]);
        }

    
        while( k > 0 ){
            s.pop();
            k--;
        }

        string result = "";
        while( !s.empty() ){

            result += s.top();
            s.pop();
        }


        while( !result.empty() && result.back() == '0'){
            result.pop_back();
        }

        reverse(result.begin(), result.end());


        if(result.empty()){
            return "0";
        }

        return result;
    }
};