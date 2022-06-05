class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPriceSoFar = INT_MAX;
        for(int i=0;i<prices.size();i++) {
            minPriceSoFar = min(minPriceSoFar, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPriceSoFar);
        }
        return maxProfit;
    }
};