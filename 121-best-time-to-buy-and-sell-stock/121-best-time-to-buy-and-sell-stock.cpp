class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minn=INT_MAX;
        for(int i=0;i<prices.size();i++) {
            minn = min(minn,prices[i]);
            profit=max(profit,prices[i]-minn);
        }
        return profit;
    }
};