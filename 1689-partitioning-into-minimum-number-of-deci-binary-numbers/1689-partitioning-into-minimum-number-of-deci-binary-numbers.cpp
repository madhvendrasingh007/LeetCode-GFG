class Solution {
public:
    int minPartitions(string n) {
        int solution = 0;
        
        for (char c : n) 
            solution = max(c-'0', solution);
        
        
        return solution;

    }
};