class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        for (int l = 0; l < searchWord.size(); ++ l) {
            auto start = lower_bound(products.begin(), products.end(), searchWord.substr(0, l+1));
            auto end = lower_bound(start, min(start+3, products.end()), searchWord.substr(0, l) + (char)(searchWord[l]+1));
            result.push_back(vector<string>(start, end));
        }
        return result;		
    }
};