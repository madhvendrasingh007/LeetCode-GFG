class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;
        
        while (iss >> word) {
            words.push_back(word);}
        
        if (pattern.size() != words.size()) {
            return false;}

        std::unordered_map<char, std::string> charToWord;
        std::unordered_set<std::string> seenWords;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const std::string& w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false;}
            } else {
                if (seenWords.count(w)) {
                    return false;}
                charToWord[c] = w;
                seenWords.insert(w); }
        }
        return true;}
};