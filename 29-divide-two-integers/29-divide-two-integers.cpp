class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor)
            return 1;
        
        unsigned int m = abs(dividend);
        unsigned int n = abs(divisor);
        unsigned int ans = 0;
        
        bool sign = (divisor > 0 == dividend > 0);
        
        while(m >= n) {
            int c = 0;
            while(m > (n<<(c+1))) {
                c++;
            }
            
            ans += (1<<c); // 1 << n == 2^n
            m -= n<<c;
        }
        
        if(ans == (1<<31) && sign)
            return pow(2,31)-1;
        return sign ? ans : -ans;
    }
};