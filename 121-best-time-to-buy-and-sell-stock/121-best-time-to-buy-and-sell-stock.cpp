class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minoff = INT_MAX,profit=0;
        for(int i=0;i<prices.size();i++)
        {
            minoff=min(minoff,prices[i]);
            profit=max(profit,prices[i]-minoff);
        }
        return profit;
    }
};