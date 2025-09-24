class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            // If any string is empty, LCP must be ""
            if (strs[i].empty()) return "";

            // Shrink prefix until it matches the start of current string
            while (strs[i].substr(0, prefix.length()) != prefix) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};
