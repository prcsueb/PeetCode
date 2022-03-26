class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int max_profit = INT_MIN;
        while (j < prices.size()) {
            int profit = prices[j] - prices[i];
            if (profit > max_profit) max_profit = profit;
            if (prices[i] > prices[j]) i = j;
            j++;
        }
        return max_profit < 0 ? 0 : max_profit;
    }
};