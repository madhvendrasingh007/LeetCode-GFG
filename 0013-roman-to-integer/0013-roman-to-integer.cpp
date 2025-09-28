class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        int n = s.length();

        for(int i=0; i<n; i++){
            int current = map[s[i]];

            if(i+1<n && map[s[i+1]] > current)
                result -= current;
            else 
                result += current;
        }

        return result;
    }
};