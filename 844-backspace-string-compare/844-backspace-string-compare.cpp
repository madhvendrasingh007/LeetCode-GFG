class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>v1,v2;
        for(auto it1:s)
        {
            if(it1=='#' && !v1.empty())
                v1.pop_back();
            else if(it1!='#')
                v1.push_back(it1);
        }
        
        for(auto it1:t)
        {
            if(it1=='#' && !v2.empty())
                v2.pop_back();
            else if(it1!='#')
                v2.push_back(it1);
    
        }
        return v1==v2;
    }
};