class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> arr(n + 1, 1);

        for (int i = 2; i <= n; i++) 
            for (int j = 1; j < i; j++)
                arr[i] = std::max(arr[i], std::max(arr[j], j) * (i - j));
        
        return arr[n];
    }
};