class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int sum = (((int)(columnTitle[0]-'A'))+1);
        for(int i=1;i<n;i++){
            sum *= 26;
            sum += ((int)(columnTitle[i]-'A')+1);
        }
        return sum;
    }
};