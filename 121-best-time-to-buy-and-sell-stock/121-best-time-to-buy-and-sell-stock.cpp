class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minn = prices[0];
        for(int i=1;i<prices.size();i++) {
            profit = max(profit, prices[i]-minn);
            minn = min(minn, prices[i]);
        }
        return profit;
    }
};