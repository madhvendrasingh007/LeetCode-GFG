class Solution {
public:
    int trailingZeroes(int n) {
        int fives {0};
        for(int i=5;i<=n;i=i*5)
            fives = fives + (n/i);
        return fives;
    }
};