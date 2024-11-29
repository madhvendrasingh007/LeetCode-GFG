class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1)
            return 1;
        int k = 0;
        int r = n;
        while (n != 1) {
            n = n / 2;
            k++;
        }
        int f = 1;
        int s = 2;
        int e = r % 2 == 0 ? r : r - 1;
        k = k - 1;
        int i=2;
        while (k--) {
            if (e <= s)
                return f?e:s;
            if (f) {
                int a = (e - s) / i + 1;
                if (a % 2 != 0) {
                    s = s + i;
                    e = e - i;
                } else {
                    e = e - i;
                }
                f = 0;
            } else {
                int a = (e - s) / i + 1;
                if (a % 2 != 0) {
                    s = s + i;
                    e = e - i;
                } else {
                    s = s + i;
                }
                f=1;
            }
            i=i*2;
        }
        return f==1?s:e;
    }
};