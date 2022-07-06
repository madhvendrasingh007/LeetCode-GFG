class Solution {
public:
    int fib(int n) {
        //if n=0 then output will be 0
        //if n=1 then output will be 1
        if(n < 2) return n;
        
        // make two pointers - prev=0, curr = 1
        int prev = 0, cur = 1;
        // iterate from i = 2 to n
        for(int i=2;i<=n;i++){
            // store the value of new element 
            int newVal = prev + cur;
            // update pervious to current & current to newVal
            prev = cur;
            cur = newVal;
        }
        // return current element
        return cur;
    }
};
