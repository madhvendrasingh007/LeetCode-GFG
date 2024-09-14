class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();
        int min_price = INT_MAX;

        for(int i=0; i<n; i++){
            min_price = min(min_price, prices[i]);
            maxPro = max(maxPro, prices[i]-min_price);
        }

        return maxPro;
    }
};