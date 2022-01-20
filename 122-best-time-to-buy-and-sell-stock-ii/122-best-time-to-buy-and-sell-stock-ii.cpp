class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDate=0;
        int sellDate=0;
        int profit=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]>prices[sellDate]) {
                sellDate=i;
            } else {
                profit+=(prices[sellDate]-prices[buyDate]);
                sellDate=buyDate=i;
            }
        }
        profit+=(prices[sellDate]-prices[buyDate]);
        return profit;
    }
};