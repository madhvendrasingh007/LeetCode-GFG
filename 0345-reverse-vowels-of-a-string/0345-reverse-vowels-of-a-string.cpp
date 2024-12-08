class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = s.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            while (vowels.find(s[left]) == vowels.end() && left < right) {
                left++;
            }
            while (vowels.find(s[right]) == vowels.end() && left < right) {
                right--;
            }

            // You have two vowels
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};