class Solution {
public:
    
    static bool comp(string a, string b) {
        return (a.length() > b.length());
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        if (words.empty())  return 0;
        sort(words.begin(), words.end(), comp);
        string str;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            s.push_back('#');
            if (str.find(s) == string :: npos) {
                str.append(s);
            }
        }
        
        return str.length();
    }
};