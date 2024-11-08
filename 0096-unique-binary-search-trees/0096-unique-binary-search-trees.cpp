class Solution {
public:
    int numTrees(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= (n+i);
        res /= i;
    }
    return res/(n+1);
    }
};